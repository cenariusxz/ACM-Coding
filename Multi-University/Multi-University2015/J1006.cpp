#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=2015;
const int maxm=1e5+5;

int dp[51][maxm];
int head[51],nxt[2500],point[2500],size;
int ans;
int n,m;
void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}
int dfs(int s,int t){
	if(dp[s][t]!=-1)return dp[s][t];
	int ans=0;
	for(int i=head[s];~i;i=nxt[i]){
		ans+=dfs(point[i],t-1);
	}
	dp[s][t]=ans%mod;
	return dp[s][t];
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(head,-1,sizeof(head));
		size=0;
		memset(dp,-1,sizeof(dp));
		ans=1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;++j){
				int b;
				scanf("%d",&b);
				add(i,b);
			}
			dp[i][1]=1;
		}
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				if(dp[j][i]!=-1)ans+=dp[j][i];
				else ans+=dfs(j,i);
			}
			ans%=mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
