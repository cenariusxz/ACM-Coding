#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
const int MAXN = 410;
const double PI = acos(-1.0);

int sgn(double x){
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point3{
	double x,y,z;
	Point3 (){}
	Point3 (double _x,double _y,double _z){
		x = _x;
		y = _y;
		z = _z;
	}
	bool operator == (Point3 &b) const{
		return (sgn(x-b.x)==0 && sgn(y-b.y)==0 && sgn(z-b.z)==0);
	}
	bool operator < (Point3 b) const{
		return sgn(x-b.x)==0?(sgn(y-b.y)==0?sgn(z-b.z)<0:y<b.y):x<b.x;
	}
	Point3 operator - (const Point3 &b) const{
		return Point3(x - b.x,y - b.y,z - b.z);
	}
	Point3 operator ^ (const Point3 &b) const{
		return Point3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
	}
	double operator * (const Point3 &b) const{
		return x * b.x + y * b.y + z * b.z;
	}
	double len(){
		return sqrt(x*x + y*y + z*z);
	}
	double len2(){
		return x * x + y * y + z * z;
	}
	double distance(Point3 p){
		double X = x - p.x;
		double Y = y - p.y;
		double Z = z - p.z;
		return sqrt(X*X + Y*Y + Z*Z);
	}
	Point3 operator + (const Point3 &b) const{
		return Point3(x + b.x,y + b.y,z + b.z);
	}
	Point3 operator * (const double &k) const{
		return Point3(x * k,y * k,z * k);
	}
	Point3 operator / (const double &k) const{
		return Point3(x / k,y / k,z / k);
	}
	Point3 trunc(double r){
		double l = len();
		if(!sgn(l)) return *this;
		r /= l;
		return Point3(x*r,y*r,z*r);
	}
};

struct Line3{
	Point3 s,e;
	Line3(){}
	Line3(Point3 _s,Point3 _e){
		s = _s;
		e = _e;
	}
	double length(){
		return s.distance(e);
	}
	double dispointtoline(Point3 p){
		return ((e-s)^(p-s)).len()/s.distance(e);
	}
};

struct Plane{
	Point3 a,b,c,o;
	Plane(){}
	Plane(Point3 _a,Point3 _b,Point3 _c){
		a = _a;
		b = _b;
		c = _c;
		o = pvec();
	}
	Point3 pvec(){
		return (b-a)^(c-a);
	}
	Plane(double _a,double _b,double _c,double _d){
		o = Point3(_a,_b,_c);
		if(sgn(_a) != 0)
			a = Point3((-_d-_c-_b)/_a,1,1);
		else if(sgn(_b) != 0)
			a = Point3(1,(-_d-_c-_a)/_b,1);
		else if(sgn(_c) != 0)
			a = Point3(1,1,(-_d-_a-_b)/_c);
	}
	int crossline(Line3 u,Point3 &p){
		double x = o*(u.e-a);
		double y = o*(u.s-a);
		double d = x-y;
		if(sgn(d) == 0) return 0;
		p = ((u.s*x) - (u.e*y))/d;
		return 1;
	}
	Point3 pointtoplane(Point3 p){
		Line3 u = Line3(p,p+o);
		crossline(u,p);
		return p;
	}
};

int T;
Point3 A[4];

int main(){
	while(scanf("%lf%lf%lf",&A[0].x,&A[0].y,&A[0].z) != EOF){
		for(int i = 1; i < 4; ++i){
			scanf("%lf%lf%lf",&A[i].x,&A[i].y,&A[i].z);
		}
		Plane P = Plane(A[0],A[1],A[2]);
		Point3 tp = P.pointtoplane(A[3]);
		for(int i = 0; i < 3; ++i){
			if(A[i] == tp) continue;
			swap(A[i],A[0]);
			break;
		}
		double tdis = A[3].distance(tp);
		if(fabs(tdis) < eps){
			printf("O O O O\n");
			continue;
		}
		Line3 L0 = Line3(A[0],A[3]),
			  L1 = Line3(A[1],A[3]),
			  L2 = Line3(A[2],A[3]);
		Line3 Lt0 = Line3(A[0],tp),
			  Lt1 = Line3(A[1],tp),
			  Lt2 = Line3(A[2],tp);
		double l=0,r=1;
		int cnt = 10;
		while(cnt--){
			double mid = (l+r)/2.0;
			Point3 cur = A[3]*mid + tp*(1.0-mid);
			double d1 = L0.dispointtoline(cur);
			double d2 = Lt0.dispointtoline(cur);
			if(d1 > d2) l = mid + eps;
			else r = mid - eps;
		}
		Point3 ans = A[3]*l + tp*(1.0-l);
		Point3 tans = P.pointtoplane(ans);
		printf("%.2f %.2f %.2f\n",ans.x,ans.y,ans.z);
		double ans_dis = ans.distance(tans);
		printf("%.4f %.4f %.4f %.4f\n",ans_dis,ans_dis,ans_dis,ans_dis);
	}
	return 0;
}


