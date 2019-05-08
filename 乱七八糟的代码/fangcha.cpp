#include<stdio.h>
#include<math.h>

int main(){
	double a[100],sum=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
	for(int i=1;i<=n;i++)sum+=a[i];
	double ave=sum/n;
	double ss=0;
	for(int i=1;i<=n;i++)ss+=(a[i]-ave)*(a[i]-ave);
	printf("%lf %lf %lf\n",ss,ss/n,ss/(n-1));
}
