#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, m;
int M[105][105][105], ans[105][105], vis[105]; 

void dfs(int s, int from, int col){
	vis[s] = 1;
	if(s != from)ans[from][s] ++;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i] || !M[col][s][i])continue;
		dfs(i, from, col);
	}
}

void init(){
	for(int i = 1 ; i <= m ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			memset(vis, 0, sizeof(vis));
			dfs(j, j, i);
		}
	}
}

void solve(){
	int q;
	scanf("%d", &q);
	while(q--){
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", ans[u][v]);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= m ; ++ i){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		M[c][a][b] = M[c][b][a] = 1;
	}
	init();
	solve();
	return 0;
}

