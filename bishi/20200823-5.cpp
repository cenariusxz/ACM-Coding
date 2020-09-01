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

int x[15], y[15], cnt;
int sx, sy, tx, ty;
int dp[2048][15], vis[15];

int cal(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	while(scanf("%d%d", &x[cnt], &y[cnt]) != EOF)++ cnt;
	for(int i = 0 ; i < cnt ; ++ i)dp[1 << i][i] = cal(sx, sy, x[i], y[i]);
	for(int state = 1 ; state < (1 << cnt) ; ++ state){
		int bits = 0;
		for(int i = 0 ; i < cnt ; ++ i){
			if(state & (1 << i))bits++, vis[i] = 1;
			else vis[i] = 0;
		}
		if(bits == 1)continue;
		for(int i = 0 ; i < cnt ; ++ i){
			if(!vis[i])continue;
			for(int j = 0 ; j < cnt ; ++ j){
				if(j == i || !vis[j])continue;
				dp[state][i] = min(dp[state][i], dp[state - (1 << i)][j] + cal(x[i], y[i], x[j], y[j]));
			}
		}
	}
	int ans = INF;
	for(int i = 0 ; i < cnt ; ++ i){
		ans = min(ans, dp[(1 << cnt) - 1][i] + cal(tx, ty, x[i], y[i]));
	}
	printf("%d\n", ans);
	return 0;
}

