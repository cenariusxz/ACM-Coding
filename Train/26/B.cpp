#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#define MAXN 310
using namespace std;
int n;
int x[310],y[310],vx[310],vy[310];

double check(double t)
{
	int i,j;
	double res=0,x1,x2,y1,y2,dis;
	for(i=1;i<=n;i++){
		x1=x[i]+t*vx[i];
		y1=y[i]+t*vy[i];
		for(j=i+1;j<=n;j++){
			x2=x[j]+t*vx[j];
			y2=y[j]+t*vy[j];
			dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
			res=max(res,dis);
		}
	}
	return res;
}

void fuck()
{
	int i,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&x[i],&y[i],&vx[i],&vy[i]);
	}
	double l=0,r=1000000,mid,midmid;
	for(t=1;t<=100;t++){
		mid=(l+r)/2;
		midmid=(r+mid)/2;
		double m=check(mid),mm=check(midmid);
		if(m>mm) l=mid;
		else r=midmid;
	}
	printf("%.2f %.2f\n",mid,check(mid));
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}
