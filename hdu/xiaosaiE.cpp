#include<stdio.h>
#include<string.h>
typedef long long ll;
typedef unsigned long long ull;

ll x,k;
int dp[65][2];
ll sum[65][2];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll ans=0;
		scanf("%I64d%I64d",&x,&k);
		for(int i=62;i>=0;--i){
			if(x&(1ll<<i)){
				dp[i][0]=1;
				dp[i][1]=0;
			}
			else{
				dp[i][0]=1;
				dp[i][1]=1;
			}
		}
		for(int i=0;i<=62;++i){
			if(i==0){
				sum[i][0]=dp[i][0];
				sum[i][1]=dp[i][1];
			}
			else{
				sum[i][0]=dp[i][0]*(sum[i-1][0]+sum[i-1][1]);
				sum[i][1]=dp[i][1]*(sum[i-1][0]+sum[i-1][1]);
			}
		}
		for(int i=62;i>=0;--i){
			if(sum[i][0]<=k){
				ans+=1ll<<i;
				k-=sum[i][0];
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
