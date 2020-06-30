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
char s[55][55];
int vis[55][55];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
bool ans;

void dfs(int x, int y, int fx, int fy){
	vis[x][y] = 1;
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = x + xx[i], dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m || s[dx][dy] != s[x][y] || (dx == fx && dy == fy))continue;
		if(vis[dx][dy]){
			ans = 1;
			return;
		}
		dfs(dx, dy, x, y);
	}
}

void solve(){
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(vis[i][j])continue;
			dfs(i, j, -1, -1);
		}
	}
	if(ans)printf("Yes\n");
	else printf("No\n");
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i] + 1);
	solve();
	return 0;
}

