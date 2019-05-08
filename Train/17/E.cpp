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
const int MAXN = 110;
const double pi = acos(-1.0);

int T,N;

int sgn(double x){
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point{
	double x,y;
	Point(){}
	double distance(Point p){
		return hypot(x-p.x,y-p.y);
	}
};

struct circle{
	Point p;
	double r;
	circle(){}
	double area(){
		return pi*r*r;
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
	double areacircle(circle v){
		int rel = relationcircle(v);
		if(rel >= 4) return 0.0;
		if(rel <= 2) return min(area(),v.area());
		double d = p.distance(v.p);
		double hf = (r+v.r+d)/2.0;
		double ss = 2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
		double a1 = acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
		a1 = a1*r*r;
		double a2 = acos((v.r*v.r + d*d - r*r) / (2.0*v.r*d));
		a2 = a2*v.r*v.r;
		return a1+a2-ss;
	}
}CC[MAXN];

bool Check(double R){
	for(int i = 1; i <= N; ++i){
		bool flag = true;
		circle TC;
		TC.p = CC[i].p;
		TC.r = R;
		for(int j = 1; j <= N; ++j){
			double tarea = TC.areacircle(CC[j]);
			if(sgn(tarea - CC[j].area() / 2.0) < 0){
				flag = false;
				break;
			}
		}
		if(flag) return true;
	}
	return false;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			CC[i].p.x = a;
			CC[i].p.y = b;
			CC[i].r = c;
		}
		double l = 0,r = 1e7;
		int cnt = 100;
		while(cnt--){
			double mid = getmid(l,r);
			if(Check(mid)) r = mid;
			else l = mid;
		}
		printf("%.4f\n",l);
	}
	return 0;
}
