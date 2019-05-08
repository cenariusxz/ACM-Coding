#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

int M[maxn][maxn];
int n,m;
int dp[maxn];
int que[maxn],vis[maxn];

int dfs(int s){
	if(dp[s])return dp[s];
	for(int i = 1 ; i <= n ; ++ i){
		if(M[s][i])dp[s] = max(dp[s], dfs(i));
	}
	dp[s]++;
	return dp[s];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++ i){
		int cnt = 0;
		scanf("%d",&cnt);
		for(int j = 1 ; j <= cnt ; ++ j)scanf("%d",&que[j]);
		for(int k = que[1] ; k <= que[cnt] ; ++ k)vis[k] = 0;
		for(int j = 1 ; j <= cnt ; ++ j)vis[que[j]] = 1;

		for(int k = que[1] ; k <= que[cnt] ; ++ k){
			if(vis[k])continue;
			for(int j = 1 ; j <= cnt ; ++ j){
				M[que[j]][k] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(!dp[i])ans = max(ans,dfs(i));
	}
	printf("%d\n",ans);
	return 0;
}
