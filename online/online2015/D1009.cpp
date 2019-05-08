#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

double get(int x1,int y1,int x2,int y2){
	return sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2));
}

int main(){
	int xa,xb,xc,ya,yb,yc;
	int T;
	scanf("%d",&T);
	for(int Q=1;Q<=T;++Q){
		scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
		double L=get(xa,ya,xb,yb);
		double d=0.5*get(xb,yb,xc,yc);
		double l=sqrt(L*L-d*d);
		double p=l*d/(L+d);
		double x=(d*d-p*p)/2.0/p;
		double R=sqrt(d*d+x*x);
		double a=acos(x/R);
		a*=2;
		double ans=a*R;
		ans+=l;
		printf("Case #%d: ",Q);
		printf("%.4lf\n",ans);
	}
	return 0;
}
