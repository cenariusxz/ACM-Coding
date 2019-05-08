#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int p[5005];
ll s[5005];
ll dp[2][5005];
ll maxx[2][5005];

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	s[0]=0;
	for(int i=1;i<=n;++i)s[i]=s[i-1]+p[i];
	memset(dp[0],0,sizeof(dp[0]));
	memset(maxx,0,sizeof(maxx));
	for(int j=1;j<=k;++j){
		int now=j&1;
		int pre=now^1;
		memset(dp[now],-1,sizeof(dp[now]));
		for(int i=m;i<=n;++i){
			if(dp[pre][i-m]>=0){
				dp[now][i]=max(dp[now][i],maxx[pre][i-m]+s[i]-s[i-m]);
			}
			maxx[now][i]=max(maxx[now][i-1],dp[now][i]);
		}
	}
	ll ans=0;
	for(int i=m;i<=n;++i){
		ans=max(ans,dp[k&1][i]);
	}
	printf("%I64d\n",ans);
	return 0;
}
