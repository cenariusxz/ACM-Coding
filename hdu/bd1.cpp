#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=1000000007;

ll dp[1000010];

void init(){
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=1000000;i++){
		dp[i]=(dp[i-1]+((i-1)*dp[i-2]%mod))%mod;
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int n;
		scanf("%d",&n);
		printf("Case #%d:\n%lld\n",q,dp[n]);
	}
	return 0;
}
