#include <bits/stdc++.h>
using namespace std;

int dp[20];
int n;

int main(){
	scanf("%d",&n);
	dp[0] = dp[1] = 1;
	for(int i = 2 ; i <= n ; ++ i){
		for(int k = 1 ; k <= i ; ++ k){
			dp[i] += dp[k-1] * dp[i-k];
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
