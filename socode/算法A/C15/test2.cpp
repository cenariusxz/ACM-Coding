#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e5 + 5;

int n,m;
vector<int> edge[maxn];
int vis[maxn];
int ans = 0;

void dfs(int s){
	vis[s] = 1;
	for(int i = 0 ; i < edge[s].size() ; ++ i){
		
		int j = edge[s][i];
		printf("%d %d",j,vis[j]);
		if(vis[j])ans = 1;
		else dfs(j);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++ i){
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].PB(v);
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		// 是否需要为 i 求连通块
		if(vis[i])continue;
		dfs(i);
		if(ans)break;
	}
	printf("%d\n",ans);
	return 0;
}

