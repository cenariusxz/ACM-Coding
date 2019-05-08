#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;

ll dp[maxn],sum[maxn];

void init(){
	dp[0] = 1;
	dp[1] = 1;
	sum[1] = dp[1];
	for(int i = 2 ; i <= 1000 ; ++ i){
		dp[i] = sum[i/2] + 1;
		sum[i] = sum[i-1] + dp[i];
	}
}

int main(){
	init();
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",dp[n]);
	}
	return 0;
}
