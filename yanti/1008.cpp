#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

const int maxn=1e5+5;

int dis[maxn],size[maxn],fa[maxn],len[maxn];
int id[maxn],dp[2][maxn];
int ans[maxn];

void init(){
	memset(dis,0,sizeof(dis));
	memset(dp,-1,sizeof(dp));
	memset(ans,0,sizeof(ans));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		init();
		scanf("%d",&n);
		for(int i=2;i<=n;++i){
			scanf("%d%d",&fa[i],&len[i]);
			id[fa[i]]++;
		}
		queue<int>q;
		for(int i=1;i<=n;++i){
			if(!id[i])q.push(i);
		}
		int ans=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			size[u]++;
			dp[0][u]=max(size[u],dp[0][u]);
			ans[u]=max(ans[u],size[u]+dis[u]);

			int f=fa[u];
			dis[f]=max(dis[f],dis[u]+len[u]);
			if(dp[0][f]!=-1)ans[f]=max(ans[f],dp[0][f]+dp[0][u]+len[u]);
			size[f]+=size[u];
			dp[0][f]=max(dp[0][f],dp[0][u]+len[u]);

			
		}
	}
	return 0;
}
