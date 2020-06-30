#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

char s[10][10]; 
int xx[5] = {0, 0, 0, 1, -1};
int yy[5] = {0, 1, -1, 0, 0};
int ans = INF;

void flip(int x, int y){
	for(int i = 0 ; i < 5 ; ++ i){
		int dx = x + xx[i], dy = y + yy[i];
		if(dx < 1 || dx > 4 || dy < 1 || dy > 4)continue;
		s[dx][dy] = (s[dx][dy] == 'b') ? 'w' : 'b';
	}
}

bool check(){
	for(int i = 1 ; i <= 4 ; ++ i){
		for(int j = 1 ; j <= 4 ; ++ j){
			if(s[i][j] != s[1][1])return 0;
		}
	}
	return 1;
}

void dfs(int x, int y, int t){
	if(x == 4 && y == 4){
		if(check())ans = min(ans, t);
		return;
	}
	if(y == 4)++ x, y = 1;
	else ++ y;
	dfs(x, y, t);
	flip(x, y);
	dfs(x, y, t+1);
	flip(x, y);
}

void solve(){
	dfs(1, 0, 0);
	if(ans == INF)printf("Impossible\n");
	else printf("%d\n", ans);
}

int main(){
	for(int i = 1 ; i <= 4 ; ++ i)scanf("%s", s[i]+1);
	solve();
	return 0;
}

