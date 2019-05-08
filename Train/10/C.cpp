#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
const int MAXN = 1500;
const int INF = 0x3f3f3f3f;

int T;
int n;

int sgn(double x){
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){
		x = _x;
		y = _y;
	}
	double len(){
		return hypot(x,y);
	}
	bool operator == (Point b) const{
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	bool operator < (Point b) const{
		return sgn(x-b.x) == 0 ? sgn(y-b.y)<0:x<b.x;
	}
	Point operator + (const Point &b) const{
		return Point(x+b.x,y+b.y);
	}
	double operator ^ (const Point &b) const{
		return x*b.y - y*b.x;
	}
	double operator * (const Point &b) const{
		return x*b.x + y*b.y;
	}
	double distance(Point p){
		return hypot(x-p.x,y-p.y);
	}
	Point trunc(double r){
		double l = len();
		if(!sgn(l)) return *this;
		r /= l;
		return Point(x*r,y*r);
	}
	Point rotleft(){
		return Point(-y,x);
	}
	Point rotright(){
		return Point(y,-x);
	}
};

struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e){
		s = _s;
		e = _e;
	}
	double length(){
		return s.distance(e);
	}
	double dispointtoline(Point p){
		return fabs((p-s)^(e-s))/length();
	}
	Point lineprog(Point p){
		return s + (((e-s)*((e-s)*(p-s)))/((e-s).len2()));
	}
	bool pointonseg(Point p){
		return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <= 0;
	}
	bool operator < (const Line &b) const{
		return s==b.s ? e<b.e : s<b.s;
	}
};

struct circle{
	Point p;
	double r;
	circle(){}
	circle(Point _p,double _r){
		p = _p;
		r = _r;
	}
	circle(double x,double y,double _r){
		p = Point(x,y);
		r = _r;
	}
	int relationcircle(circle v){
		double d = p.distance(v.p);
		if(sgn(d-r-v.r) > 0) return 5;
		if(sgn(d-r-v.r) == 0) return 4;
		double l = fabs(r-v.r);
		if(sgn(d-r-v.r)<0 && sgn(d-l)>0) return 3;
		if(sgn(d-l) == 0) return 2;
		if(sgn(d-l) < 0) return 1;
	}
	int pointcrosscircle(circle v,Point &p1,Point &p2){
		int rel = relationcircle(v);
		if(rel == 1 || rel == 5) return 0;
		double d = p.distance(v.p);
		double l = (d*d+r*r-v.r*v.r)/(2*d);
		double h = sqrt(r*r-l*l);
		Point tmp = p + (v.p-p).trunc(l);
		p1 = tmp + ((v.p-p).rotleft().trunc(h));
		p2 = tmp + ((v.p-p).rotright().trunc(h));
		if(rel == 2 || rel == 4)
			return 1;
		return 2;
	}
	int pointcrossline(Line v,Point &p1,Point &p2){
		if(!(*this).relationline(v)) return 0;
		Point a = v.lineprog(p);
		double d = v.dispointtoline(p);
		d = sqrt(r*r-d*d);
		if(sgn(d) == 0){
			p1 = a;
			p2 = a;
			return 1;
		}
		p1 = a + (v.e-v.s).trunc(d);
		p2 = a - (v.e-v.s).trunc(d);
		return 2;
	}
};

circle C[100];
Line LL[100];
int lcnt;
Point PP[MAXN];
int pcnt;
int first[MAXN],ecnt;

struct edge{
	int v,next;
}e[MAXN * MAXN * 2];

inline void add_edge(int u,int v){
	e[ecnt].next = first[u];
	e[ecnt].v = v;
	first[u] = ecnt++;
}

inline void Init(){
	memset(first,-1,sizeof(first));
	ecnt = 0;
	pcnt = 0;
}

bool Check(int a,int b){
	if(!(a < b)) swap(a,b);
	Line cur(a,b);
	lcnt = 0;
	for(int i = 1; i <= n; ++i){
		Point t1,t2;
		if(C[i].pointcrossline(cur,t1,t2) == 0){
			continue;
		}
		if(!(t1 < t2)) swap(t1,t2);
		LL[++lcnt] = Line(t1,t2);
	}
	sort(LL + 1,LL + lcnt + 1);
	int pre = 1;
	for(int i = 2; i <= lcnt; ++i){
		if(LL[i].e < LL[pre].e) continue;
		if(LL[i].pointonseg(LL[pre].e)){
			LL[pre].e = LL[i].e;
		}
		else{
			if((!(a < LL[pre].s)) && (!(LL[pre].e < b))){
				return true;
			}
			pre = i;
		}
	}
	if((!(a < LL[pre].s)) && (!(LL[pre].e < b))){
		return true;
	}
	return false;
}

queue<int> Q;
int inq[MAXN];
int dis[MAXN];

double Spfa(int st,int ed){
	while(!Q.empty()) Q.pop();
	memset(inq,0,sizeof(inq));
	fill(dis + 1,dis + pcnt + 1,INF);
	Q.push(st);
	inq[st] = 1;
	dis[st] = 0;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		for(int i = first[x]; ~i; i = e[i].next){
			int v = e[i].v;
			double d = PP[x].distance(PP[v]);
			if(dis[v] > dis[x] + d){
				dis[v] = dis[x] + d;
				if(inq[v] == 0){
					inq[v] = 1;
					Q.push(v);
				}
			}
		}
	}
	return dis[ed];
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		Init();
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i){
			int a,b,r;
			scanf("%d%d%d",&a,&b,&r);
			C[i].p = Point(a,b);
			C[i].r = r;
		}
		for(int i = 1; i <= n; ++i){
			PP[++pcnt] = C[i].p;
			for(int j = i + 1; j <= n; ++j){
				Point t1,t2;
				if(C[i].pointcrosscircle(C[j],t1,t2) == 0){
					continue;
				}
				if(t1 == t2){
					PP[++pcnt] = t1;
				}
				else{
					PP[++pcnt] = t1;
					PP[++pcnt] = t2;
				}
			}
		}
		sort(PP + 1,PP + pcnt + 1);
		pcnt = unique(PP + 1,PP + pcnt + 1) - PP - 1;
		for(int i = 1; i <= pcnt; ++i){
			for(int j = i + 1; j <= pcnt; ++j){
				if(Check(i,j)){
					add_edge(i,j);
					add_edge(j,i);
				}
			}
		}
		int st,ed;
		for(int i = 1; i <= pcnt; ++i){
			if(PP[i] == C[1].p) st = i;
			if(PP[i] == C[n].p) ed = i;
		}
		printf("Case %d: ",tt);
		double ans = Spfa(st,ed);
		if(ans >= INF){
			printf("No such path.\n");
		}
		else{
			printf("%.4f\n",ans);
		}
	}
	return 0;
}
