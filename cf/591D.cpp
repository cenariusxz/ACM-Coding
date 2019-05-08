#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int main(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int vm,t;
	scanf("%d%d",&vm,&t);
	int vx,vy,wx,wy;
	scanf("%d%d%d%d",&vx,&vy,&wx,&wy);
	
	double dx=x2-x1,dy=y2-y1;
	double dz=sqrt(dx*dx+dy*dy);
	int f1=1,f2=1;
	if(dx<0)f1*=-1;
	if(dy<0)f1*=-1;
	if(vx<0)f2*=-1;
	if(vy<0)f2*=-1;
	double ax=fabs(vx*dx/dy),ay=fabs(vy*dy/dz),bx=fabs(vx*dy/dz),dy=fabs(vy*dx/dz);
	double a,b;
	if(f1==f2)a=ax-ay;
	else a=ax+ay;
	printf("%.10lf %.10lf\n",a,b);
	double A=sqrt(vm*vm-b*b);
	double V=A+a;
	double vvx=dx*V/dz;
	double vvy=dy*V/dz;
	double Dx=vvx*t,Dy=vvy*t;
	if(Dx>dx){
		printf("%.10lf\n",dx/vvx);
		return 0;
	}
	dx-=Dx;
	dy-=Dy;
	printf("%.10lf %.10lf\n",dx,dy);
	dz=sqrt(dx*dx+dy*dy);
	a=(wx*dx+wy*dy)/dz;
	b=(wx*dy+wy*dx)/dz;
	A=sqrt(vm*vm-b*b);
	V=A+a;
	vvx=dx*V/dz;
	vvy=dy*V/dz;
	printf("%.10lf\n",dx/vvx+t);
	return 0;
}
