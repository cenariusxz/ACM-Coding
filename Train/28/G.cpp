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
const double eps = 1e-6;
const int INF = (1 << 30) - 1;
const int MAXN = 100010;

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
	Point operator - (const Point &b) const{
		return Point(x - b.x,y - b.y);
	}
	Point operator + (const Point &b) const{
		return Point(x + b.x,y + b.y);
	}
	double distance(Point p){
		return hypot(x - p.x,y - p.y);
	}
	double len(){
		return hypot(x,y);
	}
	Point trunc(double r){
		double l = len();
		if(!sgn(l)) return *this;
		r /= l;
		return Point(x * r,y * r);
	}
	Point rotleft(){
		return Point(-y,x);
	}
	Point rotright(){
		return Point(y,-x);
	}
	double operator ^ (const Point &b) const{
		return x * b.y - y * b.x;
	}
	double operator * (const Point &b) const{
		return x * b.x + y * b.y;
	}
}Pt[MAXN],PP[MAXN * 10];

int pcnt;

struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e){
		s = _s;
		e = _e;
	}
	Point crosspoint(Line v){
		double a1 = (v.e - v.s) ^ (s - v.s);
		double a2 = (v.e - v.s) ^ (e - v.s);
		return Point((s.x * a2 - e.x * a1) / (a2 - a1),
				(s.y * a2 - e.y * a1) / (a2 - a1));
	}
}L[4];

struct circle{
	Point p;
	double r;
	circle(){};
	int relation(Point b){
		double dst = b.distance(p);
		if(sgn(dst - r) < 0) return 2;
		else if(sgn(dst - r) == 0) return 1;
		return 0;
	}
	int tangentline(Point q,Line &u,Line &v){
		int x = relation(q);
		if(x == 2) return 0;
		if(x == 1){
			u = Line(q,q + (q - p).rotleft());
			v = u;
			return 1;
		}
		double d = p.distance(q);
		double l = r * r / d;
		double h = sqrt(r * r - l * l);
		u = Line(q,p + ((q - p).trunc(l) + (q - p).rotleft().trunc(h)));
		v = Line(q,p + ((q - p).trunc(l) + (q - p).rotright().trunc(h)));
		return 2;
	}
}C;

int H,W,Cx,Cy,R,N;

bool Add(Line l,int id){
	bool f = false;
	Point tp = L[id].crosspoint(l);
	if(id == 0){
		if(tp.x >= 0 && tp.x <= W)
			PP[++pcnt] = tp,f = true;
	}
	else if(id == 1){
		if(tp.y >= 0 && tp.y <= H)
			PP[++pcnt] = tp,f = true;
	}
	else if(id == 2){
		if(tp.x >= 0 && tp.x <= W)
			PP[++pcnt] = tp,f = true;
	}
	else{
		if(tp.y >= 0 && tp.y <= H)
			PP[++pcnt] = tp,f = true;
	}
	return f;
}

double Dis(Point p){
	if(p.y == H){
		return p.x;
	}
	else if(p.x == W){
		return W + H - p.y;
	}
	else if(p.y == 0){
		return W + H + W - p.x;
	}
	else{
		return W + H + W + p.y;
	}
}

map<double,int> mp;
map<double,int>::iterator it;

int main(){
	int tt = 0;
	while(scanf("%d%d%d%d%d%d",&H,&W,&R,&Cx,&Cy,&N) != EOF){
		if(H == 0 && W == 0 && R == 0 && Cx == 0 && Cy == 0 && N == 0)
			break;
		C.r = R;
		C.p = Point(Cx,Cy);
		L[0] = Line(Point(0,H),Point(W,H));
		L[1] = Line(Point(W,0),Point(W,H));
		L[2] = Line(Point(0,0),Point(W,0));
		L[3] = Line(Point(0,0),Point(0,H));
		for(int i = 1; i <= N; ++i){
			scanf("%lf%lf",&Pt[i].x,&Pt[i].y);
		}
		pcnt = 0;
		int st = N;
		mp.clear();
		for(int i = 1; i <= N; ++i){
			Line l1,l2;
			C.tangentline(Pt[i],l1,l2);
			for(int j = 0; j < 4; ++j){
				if(Add(l1,j)){
					Point v1 = l1.e - Pt[i];
					Point v2 = PP[pcnt] - Pt[i];
					double res = v1 * v2;
					if(res < 0){
						pcnt--;
					}
				}
				if(Add(l2,j)){
					Point v1 = l2.e - Pt[i];
					Point v2 = PP[pcnt] - Pt[i];
					double res = v1 * v2;
					if(res < 0){
						pcnt--;
					}
				}
			}
			if(Dis(PP[pcnt - 1]) > Dis(PP[pcnt]))
				swap(PP[pcnt],PP[pcnt - 1]);
			//printf("i : %d , (%.3f,%.3f) , (%.3f,%.3f)\n",
			//		i,PP[pcnt - 1].x,PP[pcnt - 1].y,
			//		PP[pcnt].x,PP[pcnt].y);
			//printf("pcnt : %d\n",pcnt);
			Line cenline(Pt[i],C.p);
			for(int j = 0; j < 4; ++j){
				if(Add(cenline,j)){
					Point v1 = C.p - Pt[i];
					Point v2 = PP[pcnt] - Pt[i];
					double res = v1 * v2;
					if(res < 0){
						pcnt--;
					}
				}
			}
			Point cen = PP[pcnt--];
			//printf("zhing : %f %f\n",cen.x,cen.y);
			double d1 = Dis(PP[pcnt - 1]),d2 = Dis(PP[pcnt]),
				   dc = Dis(cen);
			if(i == 5) printf("%f %f %f\n",d1,d2,dc);
			if(dc >= d1 && dc <= d2){
			//	AP[++acnt] = MP(d1,-1);
			//	AP[++acnt] = MP(d2,+1);
				mp[d1]--;
				mp[d2]++;
				printf("%f -1\n",d1);
				printf("%f +1\n",d2);
			}
			else{
				st--;
			//	AP[++acnt] = MP(d1,+1);
			//	AP[++acnt] = MP(d2,-1);
				mp[d1]++;
				mp[d2]--;
				printf("%f +1\n",d1);
				printf("%f -1\n",d2);
			}
		}
		for(int i = 1; i <= pcnt; ++i){
			printf("point %d : %f %f\n",i,PP[i].x,PP[i].y);
		}
		//sort(AP + 1,AP + acnt + 1,CMP);
		//printf("st : %d\n",st);
		//for(int i = 1; i <= acnt; ++i){
		//	printf("%.6f , %d\n",AP[i].first,AP[i].second);
		//}
		int ans = st;
		printf("st : %d\n",st);
		for(it = mp.begin(); it != mp.end(); ++it){
			printf("   %f %d\n",(*it).first,(*it).second);
			st += (*it).second;
			ans = max(ans,st);
		}
		printf("Case %d: %d\n",++tt,ans);
	}
	return 0;
}

