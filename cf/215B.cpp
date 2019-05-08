#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
	int n,a=0,b=0,p1=0,p2=0x3f3f3f3f,r1=0;
	int i,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		if(t>r1)r1=t;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		if(t>p1)p1=t;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		if(t<p2)p2=t;
	}
	scanf("%d%d",&a,&b);
	double r2=sqrt((b*p1*1.0)/(a*p2*1.0+b*p1*1.0)*r1*r1*1.0);
	printf("%.12lf\n",r2);
	return 0;
}
