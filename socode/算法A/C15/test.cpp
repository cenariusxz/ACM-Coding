#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e5 + 5;

int n, m;
vector<int> edge[maxn];
int vis[maxn];
int ans = 0, id = 0;

void dfs(int s){
	vis[s] = 1;
	for(int i = 0 ; i < edge[s].size() ; ++ i){
		int j = edge[s][i];
		if(j == id)ans = 1;
		if(vis[j])continue;
		dfs(j);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i = 1 ; i <= n ; ++ i)edge[i].clear();
		ans = 0;
		for(int i = 1 ; i <= m ; ++ i){
			int u,v;
			scanf("%d%d",&u,&v);
			edge[u].PB(v);
		}
		for(int i = 1 ; i <= n ; ++ i){
			memset(vis,0,sizeof(vis));
			id = i;
			dfs(i);
			if(ans)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}

