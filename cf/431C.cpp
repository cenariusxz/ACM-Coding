#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

ll dp[105][105][2];

int main(){
	int n,k,d;
	scanf("%d%d%d",&n,&k,&d);
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			for(int p=0;p<=n-j;++p){
				if(j>=d)dp[i][j+p][1]=(dp[i][j+p][1]+dp[i-1][p][0]+dp[i-1][p][1])%mod;
				else{
					dp[i][j+p][1]=(dp[i][j+p][1]+dp[i-1][p][1])%mod;
					dp[i][j+p][0]=(dp[i][j+p][0]+dp[i-1][p][0])%mod;
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans=(ans+dp[i][n][1])%mod;
	}
	printf("%I64d\n",ans);
}
