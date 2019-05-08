#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const double eps=1e-8;
const int maxp=10000;

int sgn(double x){
	if(fabs(x) < eps)return 0;
	if(x<0)return -1;
	return 1;
}

struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){
		x=_x;y=_y;
	}
	bool operator == (Point b)const{
		return sgn(x-b.x)==0&&sgn(y-b.y)==0;
	}
	double operator ^(const Point &b)const{
		return x*b.y-y*b.x;
	}
	double distance(Point p){
		return hypot(x-p.x,y-p.y);
	}
	Point operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	bool operator < (Point b)const{
		return sgn(x-b.x)==0?sgn(y-b.y)<0:x<b.x;
	}
	double operator * (const Point &b)const{
		return x*b.x+y*b.y;
	}
};
struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e){
		s=_s;
		e=_e;
	}
	Point crosspoint(Line v){
		double a1=(v.e-v.s)^(s-v.s);
		double a2=(v.e-v.s)^(e-v.s);
		if(fabs(a2-a1)<eps)return Point(1000000,1000000);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
	int segcrossseg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2&&(d3^d4)==-2)return 2;
		return (d1==0&&sgn((v.s-s)*(v.s-e))<=0) ||
			(d2==0 && sgn((v.e-s)*(v.e-e))<=0) ||
			(d3==0 && sgn((s-v.s)*(s-v.e))<=0) ||
			(d4==0 && sgn((e-v.s)*(e-v.e))<=0) ;
	}
	
	bool pointonseg(Point p){
		return sgn((p-s)^(e-s))==0 && sgn((p-s)*(p-e))<=0;
	}
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s))==0;
	}
};


struct polygon{
	int n;
	Point p[maxp];
	Line l[maxp];
	polygon(){n=0;}
	void add(Point q){
		p[n++]=q;
	}

	struct cmp{
		Point p;
		cmp(const Point &p0){p=p0;}
		bool operator()(const Point &aa,const Point &bb){
			Point a =aa, b=bb;
			int d =sgn((a-p)^(b-p));
			if(d==0){
				return sgn(a.distance(p)-b.distance(p)) <0;
			}
			return d>0;
		}
	};

	void norm(){
		Point mi = p[0];
		for(int i=1;i<n;++i)mi = min(mi,p[i]);
		sort(p,p+n,cmp(mi));
	}
	void getline(){
		norm();
		for(int i=0;i<n;++i){
			l[i]=Line(p[i],p[(i+1)%n]);
		}
	}

	double getarea(){
		double sum=0;
//		sort(p,p+n);
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				if(p[i].x>p[j].x||(p[i].x==p[j].x&&p[i].y>p[j].y))swap(p[i],p[j]);
			}
		}
		n = unique(p,p+n)-p;
		norm();
		for(int i=0;i<n;++i){
			sum+=(p[i] ^ p[ (i+1)%n ] );
		}
		return fabs(sum)/2;
	}
	int relationpoint(Point q){
		for(int i=0;i<n;++i){

			if(p[i]==q)return 3;
		}
		getline();
		for(int i=0;i<n;++i){
			if(l[i].pointonseg(q))return 2;
		}
		int cnt =0;
		for(int i=0;i<n;++i){
			int j=(i+1)%n;
			int k=sgn((q-p[j])^(p[i]-p[j]));
			int u=sgn(p[i].y-q.y);
			int v=sgn(p[j].y-q.y);
			if(k>0 && u<0 && v>=0)cnt++;
			if(k<0 && v<0 && u>=0)cnt--;
		}
		return cnt!=0;
	}

};


int x[10],y[10];
Point t[10];
Point r[10];

int main(){
	while(scanf("%d%d",&x[1],&y[1])!=EOF){
		for(int i=2;i<=4;++i)scanf("%d%d",&x[i],&y[i]);
		t[1]=Point(x[1],y[1]),t[2]=Point(x[1],y[2]),t[3]=Point(x[2],y[1]);
		r[1]=Point(x[3],y[3]),r[2]=Point(x[3],y[4]),r[3]=Point(x[4],y[4]),r[4]=Point(x[4],y[3]);
		polygon ans;
		polygon tt,rr;
		for(int i=1;i<=3;++i)tt.add(t[i]);
		for(int i=1;i<=4;++i)rr.add(r[i]);
		for(int i=1;i<=3;++i)if(rr.relationpoint(t[i])>=1)ans.add(t[i]);
		for(int i=1;i<=4;++i)if(tt.relationpoint(r[i])>=1)ans.add(r[i]);
		for(int i=1;i<=3;++i){
			for(int j=1;j<=4;++j){
				Line l1=Line(t[i],t[i%3+1]),l2=Line(r[j],r[j%4+1]);
				if(l1.parallel(l2))continue;
				Point tmp=l1.crosspoint(l2);
				if(l1.pointonseg(tmp)&&l2.pointonseg(tmp))ans.add(tmp);
			}
		}
		printf("%.8lf\n",ans.getarea());
	}
	return 0;
}
