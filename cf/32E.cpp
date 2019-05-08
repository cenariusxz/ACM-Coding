#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps=1e-8;

int sgn(double x){
	if(fabs(x)<eps)return 0;
	if(x<0)return -1;
	return 1;
}

struct Point{
	double x,y;
	Point(){};
	Point(double a,double b):x(a),y(b){}
	Point operator-(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	Point operator+(const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	double operator^(const Point &b)const{
		return x*b.y-y*b.x;
	}
	double operator*(const Point &b)const{
		return x*b.x+y*b.y;
	}
	double len2(){
		return x*x+y*y;
	}
};

struct Line{
	Point s,e;
	Line(){};
	Line(Point a,Point b):s(a),e(b){}
	int segcro(Line v){
		int d1=sgn((e-s)^(v.s-s));
		int d2=sgn((e-s)^(v.e-s));
		int d3=sgn((v.e-v.s)^(s-v.s));
		int d3=sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2&&(d3^d4)==-2)return 2;
		return (d1==0 && sgn((v.s-s)*(v.s-e))<=0) ||
			(d2==0 && sgn((v.e-s)*(v.e-e))<=0) ||
 			(d3==0 && sgn((s-v.s)*(s-v.e))<=0) ||
 			(d4==0 && sgn((e-v.s)*(e-v.e))<=0) ;
	}
	Point lineprog(Point p){
		return s+( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
	}
	Point symmetry(Point p){
		Point q=lineprog(p);
		return Point(2*q.x-p.x,2*q.y-p.y);
	}	
}

int main(){
	
}
