#include <bits/stdc++.h>
using namespace std;


int dp[MAXN][MAXV];

for(int i = 1 ; i <= n ; ++ i){
	for(int j = 0 ; j <= V ; ++ j){
		dp[i][j] = dp[i-1][j];
		if(j >= v[i]){
			dp[i][j] = max(dp[i][j],
					dp[i-1][j-v[i]] + w[i]);
		}
	}
}
