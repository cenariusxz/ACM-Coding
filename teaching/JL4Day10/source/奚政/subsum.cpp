#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int mod = 1e9+7;

int dp[maxn],a[505];
int n,c,sum = 0;

int main(){
	freopen("subsum.in","r",stdin);
	freopen("subsum.out","w",stdout);
	scanf("%d%d",&n,&c);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i)sum += a[i];
	dp[0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = sum ; j >= a[i] ; -- j){
			dp[j] += dp[j-a[i]];
			if(dp[j] >= mod)dp[j] -= mod;
		}
	}
	printf("%d\n",dp[c]);
	return 0;
}
