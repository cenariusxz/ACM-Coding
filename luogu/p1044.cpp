#include <bits/stdc++.h>
using namespace std;

int dp[20][20];

void init(){
	memset(dp,0,sizeof(dp));
	dp[1][1] = 1;
	for(int i = 2 ; i <= 19 ; ++ i){
		for(int j = 1 ; j <= i ; ++ j){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
}

int main(){
	init();
	int n;
	while(scanf("%d",&n)!=EOF)printf("%d\n",dp[n+1][n+1]);
	return 0;
}
