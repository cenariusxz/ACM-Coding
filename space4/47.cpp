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

int n, m, g[205][205], p[205][205], vis[205];

int main(){
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof(g));
	memset(p, -1, sizeof(p));
	memset(vis, 0, sizeof(vis));
	while(m --){
		int a, b, v;
		scanf("%d%d%d", &a, &b, &v);
		g[a][b] = g[b][a] = min(g[b][a], v);
	}
	for(int k = 1 ; k <= n ; ++ k){
		for(int i = 1 ; i <= n ; ++ i){
			for(int j = 1 ; j <= n ; ++ j){
				if(i == k || k == j || i == j)continue;
				if(g[i][k] + g[k][j] < g[i][j]){
					// printf("%d -> %d -> %d : %d, %d, %d\n", i, k, j, g[i][k], g[k][j], g[i][j]); 
					g[i][j] = g[i][k] + g[k][j], p[i][j] = k;
				}
				else if(g[i][k] + g[k][j] == g[i][j])p[i][j] = -1;
			}
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			if(i == j)continue;
			if(p[i][j] != -1)vis[p[i][j]] = 1, ans = 1;
		}
	}
	if(!ans)printf("No important .\n");
	else{
		ans = 0;
		for(int i = 1 ; i <= n ; ++ i){
			if(!vis[i])continue;
			if(ans)printf(" ");
			printf("%d", i);
			++ ans;
		}
		printf("\n");
	}
	return 0;
}

