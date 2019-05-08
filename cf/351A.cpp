#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double a[4005];

int main(){
	int n;
	scanf("%d",&n);
	int i;
	int cnt=0;
	double sum=0;
	for(i=1;i<=2*n;i++){
		double b;
		scanf("%lf",&b);
		if(fabs(b-int(b))>1e-10){a[++cnt]=fabs(b-int(b));
		sum+=a[cnt];}
	}
	int num=2*n-cnt;
	int l,r;
	double ans=0;
	if(num<n){
		l=(2*n-num*2)/2;
		r=l+num;
	}
	else{
		l=0;
		r=2*n-num;
	}
	if((double)l>sum){
		ans=l-sum;
	}
	else if((double)r<sum){
		ans=sum-r;
	}
	else{
		sum-=(int)sum;
		ans=min(sum,1-sum);
	}
	printf("%.3lf\n",fabs(ans));
	return 0;
}
