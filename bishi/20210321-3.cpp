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

int dp[2][205][205][205], n, m;
char s[205], t[5];

int main(){
	scanf("%d%d%s%s", &n, &m, s+1, t+1);
	memset(dp, -1, sizeof(dp));
	dp[0][0][0][0] = 0;
	for(int i = 0 ; i < n ; ++ i){
		int pre = i & 1;
		int nxt = pre ^ 1;
		memset(dp[nxt], -1, sizeof(dp[nxt]));
		for(int j = 0 ; j <= m ; ++ j){
			for(int k = 0 ; k <= i ; ++ k){
				for(int p = 0 ; p <= i ; ++ p){
					if(dp[pre][j][k][p] == -1)continue;
			
					
					if(s[i+1] == t[1])dp[nxt][j][k+1][p] = max(dp[nxt][j][k+1][p], dp[pre][j][k][p]);
					else if(s[i+1] == t[2])dp[nxt][j][k][p+1] = max(dp[nxt][j][k][p+1], dp[pre][j][k][p]+k);
					else dp[nxt][j][k][p] = max(dp[nxt][j][k][p], dp[pre][j][k][p]);
					
					if(j == m)continue;
					
					// ¸Ä 1
					if(s[i+1] == t[2])dp[nxt][j+1][k+1][p-1] = max(dp[nxt][j+1][k+1][p-1], dp[pre][j][k][p] - k);
					else if(s[i+1] != t[1])dp[nxt][j+1][k+1][p] = max(dp[nxt][j+1][k+1][p], dp[pre][j][k][p]);
					
					// ¸Ä 2
					if(s[i+1] == t[1])dp[nxt][j+1][k-1][p+1] = max(dp[nxt][j+1][k-1][p-1], dp[pre][j][k][p] + k-1);
					else if(s[i+1] != t[2])dp[nxt][j+1][k][p+1] = max(dp[nxt][j+1][k][p+1], dp[pre][j][k][p] + k);  
				}
			}
		}
	}
	int now = n & 1, ans = 0;
	for(int j = 0 ; j <= m ; ++ j){
		for(int k = 0 ; k <= n ; ++ k){
			for(int p = 0 ; p <= n ; ++ p){
				ans = max(ans, dp[now][j][k][p]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

