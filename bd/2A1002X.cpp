#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const ll INF=1ll<<62;
const int mod=1e9+7;

ll dp[16][16][65550];
int vis[16][16][65550];
int n;
ll a[20];
int p[20];
int num[20];

ll dfs(int pos,int i,int j){
	if(vis[pos][i][j])return dp[pos][i][j];
	if(p[i]!=-1&&p[i]!=pos){
		vis[pos][i][j]=1;
		return dp[pos][i][j]=-INF;
	}
	if(num[pos]!=-1&&num[pos]!=i){
		vis[pos][i][j]=1;
		return dp[pos][i][j]=-INF;
	}
	if(pos==0){
		vis[pos][i][j]=1;
		dp[pos][i][j]=0;
		return dp[pos][i][j];
	}
	int prej=j-(1<<i);
	dp[pos][i][j]=-INF;
	for(int prei=0;prei<n;++prei){
		if(prej&(1<<prei)){
			ll res=dfs(pos-1,prei,prej);
			if(res+a[i]*a[prei]>dp[pos][i][j])dp[pos][i][j]=res+a[i]*a[prei];
		}
	}
	vis[pos][i][j]=1;
	return dp[pos][i][j];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		memset(num,-1,sizeof(num));
		for(int i=0;i<n;++i){
			scanf("%I64d%d",&a[i],&p[i]);
			if(p[i]!=-1)num[p[i]]=i;
		}

		ll ans=-INF;
		for(int i=0;i<n;++i){
			ll res=dfs(n-1,i,(1<<n)-1);
			if(res>ans)ans=res;
		}
		printf("Case #%d:\n%I64d\n",q,ans);
	}
	return 0;
}
