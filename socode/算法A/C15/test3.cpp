#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int vis[maxn],vis2[maxn],n,m;
vector<int>V[maxn], ans;
struct Edge{
	int u,v;
}edge[maxn];

bool dfs(int u){
	vis[u]++;
	vis2[u] = 1;
	for(int i = 0 ; i < V[u].size(); ++ i){
		int v = V[u][i];
		if(vis[v] == 2)return 1;
		if(dfs(v))return 1;
	}
	vis[u] --;
	return 0;
}

void solve(){
	for(int i = 1 ; i <= n ; ++ i)V[i].clear(), vis2[i] = vis[i] = 0;
	for(int i = 0 ; i < m ; ++ i){
		V[edge[i].u].PB(edge[i].v);
	}
	
	for(int i = 1 ; i <= n ; ++ i){
		if(!vis2[i]){
			if(dfs(i)){
				ans.PB(1);
				return;	
			}
		}
	}
	ans.PB(0);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i = 0 ; i < m ; ++ i)scanf("%d%d",&edge[i].u,&edge[i].v);
		solve();	
	}
	for(int i = 0 ; i < ans.size() ; ++ i)printf("%d\n",ans[i]);
	return 0;
}

