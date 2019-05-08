#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int dp[2][10][105][105];
int vis[2][10][105][105];
//dp[2][t][i][j] -> block = t , left = i , right = j
//dp[2][t][i][j] = max/min(   dp[2][t][i][k] * sum(k+1,j)   )
//0 min   1 max
int n,m,num[105],sum[105];

int getSum(int l,int r){
	return ((sum[r] - sum[l-1]) % 10 + 10) % 10;
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i = 1 ; i <= n ; ++ i){
			scanf("%d",&num[i]);
			num[n+i] = num[i];
		}
		for(int i = 1 ; i <= 2 * n ; ++ i){
			sum[i] = sum[i-1] + num[i];
			sum[i] = (sum[i] % 10 + 10) % 10;
		}
		
		for(int i = 1 ; i <= 2*n ; ++ i){
			for(int j = i ; j - i + 1 <= n ; ++ j){
				dp[0][1][i][j] = dp[1][1][i][j] = getSum(i,j);
				vis[0][1][i][j] = vis[1][1][i][j] = 1;
			}
		}

		for(int t = 2 ; t <= m ; ++ t){
			for(int i = 1 ; i <= 2*n ; ++ i){
				for(int j = i ; j - i + 1 <= n ; ++ j){
					dp[0][t][i][j] = INF;
					dp[1][t][i][j] = -1;
					for(int k = i ; k < j ; ++ k){
						if(vis[0][t-1][i][k]){
							dp[0][t][i][j] = min(dp[0][t][i][j],
									dp[0][t-1][i][k]*getSum(k+1,j));
						}
						if(vis[1][t-1][i][k]){
							dp[1][t][i][j] = max(dp[1][t][i][j],
									dp[1][t-1][i][k]*getSum(k+1,j));
						}
					}
					if(dp[0][t][i][j] != INF)vis[0][t][i][j] = 1;
					if(dp[1][t][i][j] != -1)vis[1][t][i][j] = 1;
				}
			}
		}
		int ans0 = INF,ans1 = -1;
		for(int i = 1 ; i <= n ; ++ i){
			int j = i + n - 1;
			ans0 = min(ans0, dp[0][m][i][j]);
			ans1 = max(ans1, dp[1][m][i][j]);
		}
		printf("%d\n%d\n",ans0,ans1);
	}
	return 0;
}
