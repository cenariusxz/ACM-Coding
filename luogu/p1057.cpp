#include <bits/stdc++.h>
using namespace std;

int dp[35][35];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int t = 1 ; t <= m ; ++ t){
			for(int i = 0 ; i < n ; ++ i){
				int left = (i - 1 + n) % n;
				int right = (i + 1) % n;
				dp[t][i] = dp[t-1][left] + dp[t-1][right];
			}
		}
		printf("%d\n",dp[m][0]);
	}
	return 0;
}
