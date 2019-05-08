#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 7;

int dp[105][105];
int a[105];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++i)scanf("%d",&a[i]);
	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 0 ; j <= m ; ++ j){
			for(int k = 0 ; k <= min(j,a[i]) ; ++ k){
				dp[i][j] += dp[i-1][j-k];
				dp[i][j] %= mod;
			}
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
