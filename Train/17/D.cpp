#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 1100;
const double pi = acos(-1.0);

int T,N,M;

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
	double distance(Point p){
		return hypot(x-p.x,y-p.y);
	}
	double operator ^ (const Point &b) const{
		return x*b.y - y*b.x;
	}
	double operator * (const Point &b) const{
		return x*b.x + y*b.y;
	}
	bool operator == (Point b) const{
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	bool operator < (Point b) const{
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0 : x < b.x;
	}
	Point operator + (const Point &b) const{
		return Point(x+b.x,y+b.y);
	}
	Point operator - (const Point &b) const{
		return Point(x-b.x,y-b.y);
	}
	Point operator * (const double &k) const{
		return Point(x*k,y*k);
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
	bool pointonseg(Point p){
		return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <= 0;
	}
	double dispointtoline(Point p){
		return fabs((p-s)^(e-s))/length();
	}
	Point crosspoint(Line v){
		double a1 = (v.e-v.s)^(s-v.s);
		double a2 = (v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),
				(s.y*a2-e.y*a1)/(a2-a1));
	}
};

struct polygon{
	int n;
	Point p[MAXN];
	Line l[MAXN];
	void getline(){
		for(int i = 0; i < n; ++i){
			l[i] = Line(p[i],p[(i + 1) % n]);
		}
	}
	int relationpoint(Point q){
		for(int i = 0; i < n; ++i){
			if(p[i] == q) return 3;
		}
		getline();
		for(int i = 0; i < n; ++i){
			if(l[i].pointonseg(q)) return 2;
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			int j = (i + 1) % n;
			int k = sgn((q-p[j])^(p[i]-p[j]));
			int u = sgn(p[i].y-q.y);
			int v = sgn(p[j].y-q.y);
			if(k > 0 && u < 0 && v >= 0) cnt++;
			if(k < 0 && v < 0 && u >= 0) cnt--;
		}
		return cnt != 0;
	}
	struct cmp{
		Point p;
		cmp(const Point &p0){ p = p0; }
		bool operator ()(const Point &aa,const Point &bb){
			Point a = aa,b = bb;
			int d = sgn((a-p)^(b-p));
			if(d == 0){
				return sgn(a.distance(p)-b.distance(p)) < 0;
			}
			return d > 0;
		}
	};
	void norm(){
		Point mi = p[0];
		for(int i = 1; i < n; ++i) mi = min(mi,p[i]);
		sort(p,p + n,cmp(mi));
	}
	void Graham(polygon &convex){
		norm();
		int &top = convex.n;
		top = 0;
		if(n == 1){
			top = 1;
			convex.p[0] = p[0];
			return;
		}
		if(n == 2){
			top = 2;
			convex.p[0] = p[0];
			convex.p[1] = p[1];
			if(convex.p[0] == convex.p[1]) top--;
			return;
		}
		convex.p[0] = p[0];
		convex.p[1] = p[1];
		top = 2;
		for(int i = 2; i < n; ++i){
			while(top > 1 && sgn((convex.p[top - 1]-convex.p[top-2])
					^(p[i]-convex.p[top-2])) <= 0)
				top--;
			convex.p[top++] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n--;
	}
}hole,coin,conv;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		hole.n = N;
		for(int i = 0; i < N; ++i){
			double a,b;
			scanf("%lf%lf",&a,&b);
			hole.p[i] = Point(a,b);
		}
		scanf("%d",&M);
		coin.n = M;
		for(int i = 0; i < M; ++i){
			double a,b;
			scanf("%lf%lf",&a,&b);
			coin.p[i] = Point(a,b);
		}
		coin.Graham(conv);
		int top = conv.n;
		double LL = INF;
		for(int i = 0; i < top; ++i){
			Line tline = Line(conv.p[i],conv.p[(i + 1) % top]);
			double tmax = -INF;
			for(int j = 0; j < top; ++j){
				double dis = tline.dispointtoline(conv.p[j]);
				tmax = max(tmax,dis);
			}
			LL = min(LL,tmax);
		}
		//printf("LL : %.4f\n",LL);
		double ML = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j) if(i != j){
				vector<Point> V;
				Line Lij = Line(hole.p[i],hole.p[j]);
				for(int o = 0; o < N; ++o){
					int oo = (o + 1) % N;
					Line cur = Line(hole.p[o],hole.p[oo]);
					Point cp = cur.crosspoint(Lij);
					if(cur.pointonseg(cp)){
						V.PB(cp);
					}
				}
				if(V.empty()) continue;
				sort(V.begin(),V.end());
				vector<Point> TV;
				TV.PB(V[0]);
				for(int o = 1; o < V.size(); ++o){
					if(TV[TV.size() - 1] == V[o]) continue;
					TV.PB(V[o]);
				}
				vector<Line> TL,NL;
				Line tmp;
				bool FLAG = 0;
				for(int o = 0; o < TV.size() - 1; ++o){
					TL.PB(Line(TV[o],TV[o + 1]));
				}
				for(int o = 0; o < TL.size(); ++o){
					Point mid = Point((TL[o].s.x + TL[o].e.x)/2,
						(TL[o].s.y + TL[o].e.y)/2);
					int rel = hole.relationpoint(mid);
					if(rel != 0){
						// 内部
						if(FLAG == 0){
							tmp = TL[o];
						}
						else{
							tmp.e = TL[o].e;
						}
						FLAG = 1;
					}
					else{
						NL.PB(tmp);
						FLAG = 0;
					}
				}
				if(FLAG){
					NL.PB(tmp);
					FLAG = 0;
				}
				for(int o = 0; o < NL.size(); ++o){
					ML= max(ML,NL[o].length());
				}
			}
		}
		//printf("ML : %.4f\n",ML);
		if(sgn(ML - LL) < 0) printf("illegal\n");
		else printf("legal\n");
	}
	return 0;
}
