#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
const double eps=1e-9;
const int maxn=2e5+5;

int a[maxn];
double dp[maxn];

inline double max(double a,double b){
	return a>b?a:b;
}

int main(){
	int n;
	scanf("%d",&n);
	double l=1e5,r=-1e5;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]<l)l=a[i];
		if(a[i]>r)r=a[i];
	}
	double ans=1e15;
	double mp,mn;
	for(int p=1;p<=50;p++){
		double m=(l+r)/2.0;
		mp=0,mn=0;
		dp[0]=0;
		for(int i=1;i<=n;++i){
			if(dp[i-1]>0){
				dp[i]=dp[i-1]+a[i]-m;
			}
			else dp[i]=a[i]-m;
			if(dp[i]>mp)mp=dp[i];
		}
		dp[0]=0;
		for(int i=1;i<=n;++i){
			if(dp[i-1]<0){
				dp[i]=dp[i-1]+a[i]-m;
			}
			else dp[i]=a[i]-m;
			if(dp[i]<mn)mn=dp[i];
		}
//		if(max(mp,0-mn)<ans)ans=max(mp,0-mn);
		if(mp>0-mn)l=m;
		else r=m;
	}
	printf("%.15lf\n",max(mp,0-mn));
}
