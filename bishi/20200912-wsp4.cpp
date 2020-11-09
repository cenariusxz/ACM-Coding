#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int a[maxn], n, dp[maxn][7];

int main(){
	int num;
	while(scanf("%d", &num) != EOF){
		a[++n] = num;
		//if(n == 2)break;	// test
	}
	memset(dp, -1, sizeof(dp));;
	dp[0][0] = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 0 ; j < 7 ; ++ j)dp[i][j] = dp[i-1][j];
		for(int j = 0 ; j < 7 ; ++ j){
			if(dp[i-1][j] == -1)continue;
			dp[i][(j+a[i])%7] = max(dp[i][(j+a[i])%7], dp[i-1][j] + a[i]);
		}
	}
	if(!dp[n][0])dp[n][0] = -1;
	printf("%d\n", dp[n][0]);
	return 0;
}

