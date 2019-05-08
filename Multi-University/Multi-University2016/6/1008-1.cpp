#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

ll dp[2][maxn][3][3];
int a[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,s;
		scanf("%d%d",&n,&s);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[0][0][0][0]=1;
		for(int now=1;now<=n;++now){
			int i=now&1,ii=i^1;
			memset(dp[i],0,sizeof(dp[i]));
			for(int j=0;j<=s;++j){
				if(j>=a[now]){
					dp[i][j][0][0]=(dp[ii][j-a[now]][0][0]+dp[ii][j][0][0])%mod;
					dp[i][j][0][1]=(dp[ii][j][0][0]+dp[ii][j-a[now]][0][1]+dp[ii][j][0][1])%mod;
					dp[i][j][0][2]=(dp[ii][j][0][1]+dp[ii][j-a[now]][0][2]+dp[ii][j][0][2])%mod;
					dp[i][j][1][0]=(dp[ii][j-a[now]][0][0]+dp[ii][j-a[now]][1][0]+dp[ii][j][1][0])%mod;
					dp[i][j][1][1]=(dp[ii][j-a[now]][0][1]+dp[ii][j][1][0]+dp[ii][j-a[now]][1][1]+dp[ii][j][1][1])%mod;
					dp[i][j][1][2]=(dp[ii][j-a[now]][0][2]+dp[ii][j][1][1]+dp[ii][j-a[now]][1][2]+dp[ii][j][1][2])%mod;
					dp[i][j][2][0]=(dp[ii][j-a[now]][1][0]+dp[ii][j-a[now]][2][0]+dp[ii][j][2][0])%mod;
					dp[i][j][2][1]=(dp[ii][j-a[now]][1][1]+dp[ii][j][2][0]+dp[ii][j-a[now]][2][1]+dp[ii][j][2][1])%mod;
					dp[i][j][2][2]=(dp[ii][j-a[now]][1][2]+dp[ii][j][2][1]+dp[ii][j-a[now]][2][2]+dp[ii][j][2][2])%mod;
				}
				else{
					dp[i][j][0][0]=dp[ii][j][0][0];
					dp[i][j][0][1]=(dp[ii][j][0][0]+dp[ii][j][0][1])%mod;
					dp[i][j][0][2]=(dp[ii][j][0][1]+dp[ii][j][0][2])%mod;
					dp[i][j][1][0]=dp[ii][j][1][0];
					dp[i][j][1][1]=(dp[ii][j][1][0]+dp[ii][j][1][1])%mod;
					dp[i][j][1][2]=(dp[ii][j][1][1]+dp[ii][j][1][2])%mod;
					dp[i][j][2][0]=dp[ii][j][2][0];
					dp[i][j][2][1]=(dp[ii][j][2][0]+dp[ii][j][2][1])%mod;
					dp[i][j][2][2]=(dp[ii][j][2][1]+dp[ii][j][2][2])%mod;
				}
			}
		}
		ll ans=0;
		for(int i=0;i<=s;++i){
			ans+=dp[n&1][i][2][2];
			if(ans>=mod)ans-=mod;
		}
		printf("%lld\n",ans*4%mod);
	}
	return 0;
}
