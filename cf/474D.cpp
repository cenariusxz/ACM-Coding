#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int maxn=1e5+5;

ll dp[2][maxn];
ll s[maxn];
//0 R 1 W
int t,k;

void init(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	dp[1][0]=0;
	for(int i=1;i<=100000;++i){
		dp[0][i]=dp[0][i-1]+dp[1][i-1];
		if(dp[0][i]>=mod)dp[0][i]-=mod;
		if(i-k>=0){
			dp[1][i]=dp[0][i-k]+dp[1][i-k];
			if(dp[1][i]>=mod)dp[1][i]-=mod;
		}
	}
	s[0]=0;
	for(int i=1;i<=100000;++i){
		s[i]=s[i-1]+dp[0][i]+dp[1][i];
		s[i]%=mod;
	}
}

int main(){
	scanf("%d%d",&t,&k);
	init();
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%I64d\n",((s[b]-s[a-1])%mod+mod)%mod);
	}
	return 0;
}
