#include <bits/stdc++.h>
using namespace std;

int n, t, a[105], num[5], dp[5][45][45][45][45];

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	scanf("%d", &t);
	for(int i = 1 ; i <= t ; ++ i){
		int tmp;
		scanf("%d", &tmp);
		num[tmp] ++;
	}
	memset(dp, -1, sizeof(dp));
	dp[1][num[1]][num[2]][num[3]][num[4]] = a[1];
	int ans = a[1];
	for(int m = 1 ; m < n ; ++ m){
		int now = m % 5;
		int pre = (m - 1) % 5;
		memset(dp[pre], -1, sizeof(dp[pre]));
		for(int i = 0 ; i <= num[1] ; ++ i){
			for(int j = 0 ; j <= num[2] ; ++ j){
				for(int k = 0 ; k <= num[3] ; ++ k){
					for(int p = 0 ; p <= num[4] ; ++ p){
						if(dp[now][i][j][k][p] == -1)continue;
						int tmp, nxt;
						if(i && m + 1 <= n){
							nxt = (m+1) % 5;
							tmp = dp[now][i][j][k][p] + a[m+1];
							ans = max(ans, tmp);
							dp[nxt][i-1][j][k][p] = max(dp[nxt][i-1][j][k][p], tmp);
						}
						if(j && m + 2 <= n){
							nxt = (m+2) % 5;
							tmp = dp[now][i][j][k][p] + a[m+2];
							ans = max(ans, tmp);
							dp[nxt][i][j-1][k][p] = max(dp[nxt][i][j-1][k][p], tmp);
						}
						if(k && m + 3 <= n){
							nxt = (m+3) % 5;
							tmp = dp[now][i][j][k][p] + a[m+3];
							ans = max(ans, tmp);
							dp[nxt][i][j][k-1][p] = max(dp[nxt][i][j][k-1][p], tmp);
						}
						if(p && m + 4 <= n){
							nxt = (m+4) % 5;
							tmp = dp[now][i][j][k][p] + a[m+4];
							ans = max(ans, tmp);
							dp[nxt][i][j][k][p-1] = max(dp[nxt][i][j][k][p-1], tmp);
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

