#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn=1e6+5;

int a[maxn];
int dp[2][2][1005];
bool vis[2][2][1005];

int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		dp[1][1][1]=a[1];
		vis[1][1][1]=1;
		dp[1][0][0]=0;
		vis[1][0][0]=1;
		for(int k=1;k<n;++k){
			int i=k&1;
			memset(vis[i^1],0,sizeof(vis[i^1]));
			for(int j=0;j<=m;++j){
				if(vis[i][0][j]){
					if(!vis[i^1][0][j]){
						vis[i^1][0][j]=1;
						dp[i^1][0][j]=dp[i][0][j];
					}
					else if(dp[i][0][j]>dp[i^1][0][j])dp[i^1][0][j]=dp[i][0][j];
					if(!vis[i^1][1][j+1]){
						vis[i^1][1][j+1]=1;
						dp[i^1][1][j+1]=dp[i][0][j]+a[k+1];
					}
					else if(dp[i][0][j]+a[k+1]>dp[i^1][1][j+1])dp[i^1][1][j+1]=dp[i][0][j]+a[k+1];
				}
				if(vis[i][1][j]){
					if(!vis[i^1][0][j]){
						vis[i^1][0][j]=1;
						dp[i^1][0][j]=dp[i][1][j];
					}
					else if(dp[i][1][j]>dp[i^1][0][j])dp[i^1][0][j]=dp[i][1][j];
					if(!vis[i^1][1][j]){
						vis[i^1][1][j]=1;
						dp[i^1][1][j]=dp[i][1][j]+a[k+1];
					}
					else if(dp[i][1][j]+a[k+1]>dp[i^1][1][j])dp[i^1][1][j]=dp[i][1][j]+a[k+1];
					if(!vis[i^1][1][j+1]){
						vis[i^1][1][j+1]=1;
						dp[i^1][1][j+1]=dp[i][1][j]+a[k+1];
					}
					else if(vis[i^1][1][j+1]&&dp[i][1][j]+a[k+1]>dp[i^1][1][j+1])dp[i^1][1][j+1]=dp[i][1][j]+a[k+1];
				}
			}
		}
		int ans=-0x3f3f3f3f;
		if(vis[n&1][1][m])ans=max(ans,dp[n&1][1][m]);
		if(vis[n&1][0][m])ans=max(ans,dp[n&1][0][m]);
		printf("%d\n",ans);
	}
	return 0;
}
