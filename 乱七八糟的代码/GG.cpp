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
const long double eps = 1e-12;
const int INF = (1 << 30) - 1;
const int MAXN = 100010;

int sgn(long double x){
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point{
	long double x,y;
	Point(){}
	Point(long double _x,long double _y){
		x = _x;
		y = _y;
	}
	Point operator - (const Point &b) const{
		return Point(x - b.x,y - b.y);
	}
	Point operator + (const Point &b) const{
		return Point(x + b.x,y + b.y);
	}
	long double distance(Point p){
		return hypot(x - p.x,y - p.y);
	}
	long double len(){
		return hypot(x,y);
	}
	Point trunc(long double r){
		long double l = len();
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
	long double operator ^ (const Point &b) const{
		return x * b.y - y * b.x;
	}
	long double operator * (const Point &b) const{
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
		long double a1 = (v.e - v.s) ^ (s - v.s);
		long double a2 = (v.e - v.s) ^ (e - v.s);
		return Point((s.x * a2 - e.x * a1) / (a2 - a1),
				(s.y * a2 - e.y * a1) / (a2 - a1));
	}
}L[4];

struct circle{
	Point p;
	long double r;
	circle(){};
	int relation(Point b){
		long double dst = b.distance(p);
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
		long double d = p.distance(q);
		long double l = r * r / d;
		long double h = sqrt(r * r - l * l);
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
		if(fabs(tp.x) < eps || (tp.x > 0 && tp.x < W) ||
				fabs(tp.x - W) < eps)
			PP[++pcnt] = tp,f = true;
	}
	else if(id == 1){
		if(fabs(tp.y - H) < eps || (tp.y > 0 && tp.y < H) ||
				fabs(tp.y) < eps)
			PP[++pcnt] = tp,f = true;
	}
	else if(id == 2){
		if(fabs(tp.x - W) < eps || (tp.x > 0 && tp.x < W) ||
				fabs(tp.x) < eps)
			PP[++pcnt] = tp,f = true;
	}
	else{
		if(fabs(tp.y) < eps || (tp.y > 0 && tp.y < H) ||
				fabs(tp.y - H) < eps)
			PP[++pcnt] = tp,f = true;
	}
	return f;
}

long double Dis(Point p){
	if(fabs(p.y - H) < eps){
		return p.x;
	}
	else if(fabs(p.x - W) < eps){
		return W + H - p.y;
	}
	else if(fabs(p.y) < eps){
		return W + H + W - p.x;
	}
	else{
		return W + H + W + p.y;
	}
}

pair<long double,int> AP[MAXN * 10];
int acnt;

bool CMP(pair<long double,int> a,pair<long double,int> b){
	if(fabs(a.first - b.first) < eps) return a.second > b.second;
	return a.first < b.first;
}

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
			double a,b;
			scanf("%lf%lf",&a,&b);
			Pt[i].x = a;
			Pt[i].y = b;
		}
		pcnt = 0;
		acnt = 0;
		int st = N;
		for(int i = 1; i <= N; ++i){
			Line l1,l2;
			C.tangentline(Pt[i],l1,l2);
			for(int j = 0; j < 4; ++j){
				if(Add(l1,j)){
					Point v1 = l1.e - Pt[i];
					Point v2 = PP[pcnt] - Pt[i];
					long double res = v1 * v2;
					if(res < 0){
						pcnt--;
					}
				}
				if(Add(l2,j)){
					Point v1 = l2.e - Pt[i];
					Point v2 = PP[pcnt] - Pt[i];
					long double res = v1 * v2;
					if(res < 0){
						pcnt--;
					}
				}
			}
			if(Dis(PP[pcnt - 1]) > Dis(PP[pcnt]))
				swap(PP[pcnt],PP[pcnt - 1]);
			Line cenline(Pt[i],C.p);
			for(int j = 0; j < 4; ++j){
				if(Add(cenline,j)){
					Point v1 = C.p - Pt[i];
					Point v2 = PP[pcnt] - Pt[i];
					long double res = v1 * v2;
					if(res < 0){
						pcnt--;
					}
				}
			}
			Point cen = PP[pcnt--];
			long double d1 = Dis(PP[pcnt - 1]),d2 = Dis(PP[pcnt]),
				   dc = Dis(cen);
			if(dc >= d1 && dc <= d2){
				AP[++acnt] = MP(d1,-1);
				AP[++acnt] = MP(d2,+1);
			}
			else{
				st--;
				AP[++acnt] = MP(d1,+1);
				AP[++acnt] = MP(d2,-1);
			}
		}
		//for(int i = 1; i <= pcnt; ++i){
		//	printf("point %d : %f %f\n",i,PP[i].x,PP[i].y);
		//}
		sort(AP + 1,AP + acnt + 1,CMP);
		//printf("st : %d\n",st);
		//for(int i = 1; i <= acnt; ++i){
		//	printf("%.6f , %d\n",AP[i].first,AP[i].second);
		//}
		int ans = st;
		for(int i = 1; i <= acnt; ++i){
			//printf("  %f --> %d\n",AP[i].first,AP[i].second);
			st += AP[i].second;
			ans = max(ans,st);
		}
		/*map<long double,int>::iterator it;
		for(it = mp.begin(); it != mp.end(); ++it){
			st += (*it).second;
			ans = max(ans,st);
		}*/
		printf("Case %d: %d\n",++tt,max(1,ans));
	}
	return 0;
}
