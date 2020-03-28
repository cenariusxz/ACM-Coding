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

int n, m, x, y;
char s[maxn][maxn];
int cost[maxn][2], dp[maxn][maxn][2];

int main(){
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i] + 1);
	for(int i = 1 ; i <= m ; ++ i){
		for(int j = 1 ; j <= n ; ++ j ){
			if(s[j][i] == '#')cost[i][0] ++;
			else cost[i][1] ++;
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[1][1][0] = cost[1][0];
	dp[1][1][1] = cost[1][1];
	for(int i = 1 ; i < m ; ++ i){
		for(int j = 1 ; j <= min(i, y) ; ++ j){
			for(int col = 0 ; col <= 1 ; ++ col){
				if(dp[i][j][col] == -1)continue;
				if(j+1 <= y)dp[i+1][j+1][col] = min(dp[i+1][j+1][col], dp[i][j][col] + cost[i+1][col]);
				if(j >= x)dp[i+1][1][col^1] = min(dp[i+1][1][col^1], dp[i][j][col] + cost[i+1][col^1]);
			}
		}
	}
	int ans = INF;
	for(int i = x ; i <= y ; ++ i){
		ans = min(ans, dp[m][i][0]);
		ans = min(ans, dp[m][i][1]);
	}
	printf("%d\n", ans);
	return 0;
}

