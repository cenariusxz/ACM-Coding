#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 5;

int n,m;
char s[maxn][maxn];
int vis[maxn][maxn];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
	vis[x][y] = 1;
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = x + xx[i], dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m || vis[dx][dy] || s[dx][dy] == '.')continue;
		dfs(dx, dy);
	}
}

void solve(){
	int num = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '#')num ++;
		}
	}
	if(num == 0){
		printf("0\n");
		return;
	}
	
	bool flaga = 0, flagb = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int res = 0, fst = 0, lst = 0;
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '#'){
				res ++;
				if(fst == 0)fst = j;
				lst = j;
			}
		}
		if(res == 0)flaga = 1;
		else if(res != lst - fst + 1){
			printf("-1\n");
			return;
		}
		
	}
	for(int j = 1 ; j <= m ; ++ j){
		int res = 0, fst = 0, lst = 0;
		for(int i = 1 ; i <= n ; ++ i){
			if(s[i][j] == '#'){
				res ++;
				if(fst == 0)fst = i;
				lst = i;
			}
		}
		if(res == 0)flagb = 1;
		else if(res != lst - fst + 1){
			printf("-1\n");
			return;
		}
	}
	
	if(flaga != flagb){
		printf("-1\n");
		return;
	}
	
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(vis[i][j] || s[i][j] == '.')continue;
			dfs(i,j);
			ans ++;
		}
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i] + 1);
	solve();
	return 0;
}

