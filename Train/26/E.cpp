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

int T;

struct Point{
	double x,y;
	Point(){}
	Point(double tx,double ty){
		x = tx;
		y = ty;
	}
};

Point F(Point a,Point b,Point c){
	double a1 = a.x - b.x;
	double a2 = a.x - c.x;
	double b1 = a.y - b.y;
	double b2 = a.y - c.y;
	double c1 = a.x*a.x + a.y*a.y - b.x*b.x - b.y*b.y;
	double c2 = a.x*a.x + a.y*a.y - c.x*c.x - c.y*c.y;
	double t = (a1*b2 - a2*b1)*2.0;
	return Point((c1*b2-c2*b1)/t,(a1*c2-a2*c1)/t);
}

double Dis(Point a,Point b){
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x*x + y*y);
}



int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		Point p[4];
		double d[3]; 
		for(int i = 0; i < 4; ++i){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		d[0] = Dis(p[0],p[1]);
		d[1] = Dis(p[0],p[2]);
		d[2] = Dis(p[1],p[2]);
		Point cen = F(p[0],p[1],p[2]);
		if(d[1]*d[1] + d[2]*d[2] < d[0]*d[0]){
			cen = Point((p[0].x+p[1].x)/2.0,(p[0].y+p[1].y)/2.0);
		}
		else if(d[0]*d[0] + d[2]*d[2] < d[1]*d[1]){
			cen = Point((p[0].x+p[2].x)/2.0,(p[0].y+p[2].y)/2.0);
		}
		else if(d[0]*d[0] + d[1]*d[1] < d[2]*d[2]){
			cen = Point((p[1].x+p[2].x)/2.0,(p[1].y+p[2].y)/2.0);
		}
		double r = Dis(cen,p[0]);
		double tr = Dis(cen,p[3]);
		//printf("r : %.3f %.3f\n",r,tr);
		printf("Case #%d: ",tt);
		if(tr > r){
			printf("Safe\n");
		}
		else{
			printf("Danger\n");
		}
	}
	return 0;
}


