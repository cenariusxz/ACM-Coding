#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int n, m;
ll a[maxn], dp[maxn];

inline ll max(ll a, ll b){return a > b ? a : b;}

ll DP(int cnt){
	for(int i = 1 ; i <= cnt ; ++ i){
		dp[i] = dp[i-1] < 0 ? a[i] : dp[i-1] + a[i];
	}
	ll ans = dp[1];
	for(int i = 2 ; i <= cnt ; ++ i)ans = max(ans, dp[i]);
	return ans;
}

ll solve(){
	if(m == 1)return DP(n);
	for(int i = 1 ; i <= n ; ++ i)a[n+i] = a[i];
	if(m == 2)return DP(n * 2);
	ll sum = 0;
	for(int i = 1 ; i <= n ; ++ i)sum += a[i];
	if(sum >= 0)return DP(n * 2) + sum * (m-2);
	else return DP(n * 2);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	printf("%lld\n", solve());
	return 0;
}

