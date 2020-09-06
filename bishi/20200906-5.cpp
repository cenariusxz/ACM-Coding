#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int n, k;
ll dp[maxn];

int main(){
	scanf("%d%d", &n, &k);
	dp[0] = dp[1] = 1;
	for(int i = 2 ; i <= n ; ++ i){
		if(i % k == 0)continue;
		for(int j = n ; j >= i ; -- j){
			dp[j] += dp[j-i];
		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}

