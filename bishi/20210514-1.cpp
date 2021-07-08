#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int n, x, y, z;
ll dp[maxn]; 

int main(){
	scanf("%d%d%d%d", &n, &x, &y, &z);
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		if(i >= x)dp[i] += dp[i-x];
		if(i >= y)dp[i] += dp[i-y];
		if(i >= z)dp[i] += dp[i-z];
		dp[i] %= mod;
	}
	printf("%lld\n", dp[n]);
	return 0;
}

