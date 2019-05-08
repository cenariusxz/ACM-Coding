#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n,k,s;
long long dp[30][20][200];

int main(){
	while(scanf("%d%d%d",&n,&k,&s) != EOF){
		if(n == 0 && k == 0 && s == 0) break;
		memset(dp,0,sizeof(dp));
		dp[0][0][0] = 1;
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j <= k; ++j){
				for(int o = 0; o <= s; ++o){
					dp[i][j][o] = dp[i - 1][j][o];
					if(j && (o >= i)){
						dp[i][j][o] += dp[i - 1][j - 1][o - i];
					}
				}
			}
		}
		cout << dp[n][k][s] << endl;
	}
	return 0;
}
