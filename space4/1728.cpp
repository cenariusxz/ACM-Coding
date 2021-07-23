#include <bits/stdc++.h>	//449D
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 3e6 + 5;

int n, a[maxn];
ll dp[maxn], pw2[maxn], bits[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)dp[a[i]]++;
	pw2[0] = 1;
	for(int i = 1 ; i <= n ; ++ i)pw2[i] = pw2[i-1] * 2 % mod;
	for(int i = 0 ; i < 20 ; ++ i){
		for(int j = 0 ; j < (1 << 20) ; ++ j){
			if(!(j & (1 << i)))dp[j] = (dp[j] + dp[j^(1<<i)]) % mod;
		}
	}
	ll ans = 0;
	for(int i = 0 ; i < (1 << 20) ; ++ i){
		int bits = 0;
		for(int j = 0 ; j < 20 ; ++ j){
			if(i & (1<<j))++ bits;
		}
		if(bits & 1)ans = (ans - pw2[dp[i]] + 1 + mod) % mod;
		else ans = (ans + pw2[dp[i]] - 1 + mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

