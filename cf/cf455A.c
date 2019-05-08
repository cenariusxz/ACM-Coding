#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define ll long long
/*
struct num{
	int a,t;
}p[100005]*/
ll a[100005];
ll dp[100005];

int main(){
	ll n;
	while(scanf("%I64d",&n)!=EOF){
		ll i,j,t,m=0,mi=0xFFFFFFF;
		ll ans=0;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			scanf("%I64d",&t);
			a[t]++;
			m=max(m,t);
		}
		dp[1]=a[1];
		dp[2]=2*a[2];
		ans=max(dp[1],dp[2]);
		for(i=3;i<=m;i++){

			for(j=i-3;j<=i-2;j++){
				dp[i]=max(dp[i],dp[j]+a[i]*i);
			}
			ans=max(ans,dp[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
