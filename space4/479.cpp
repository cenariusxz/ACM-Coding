#include <bits/stdc++.h>	//451E
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n;
ll s, f[maxn], ans;

ll QP(ll a, ll n){
	ll ans = 1, tmp = a % mod;
	while(n){
		if(n & 1)ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}

ll C(ll n, ll m){
	if(n < 0 || m < 0 || n < m)return 0;
	ll up = 1, down = 1;
	n %= mod;
	for(ll i = 0 ; i < m ; ++ i){
		up = up * ((n - i + mod) % mod) % mod;
		down = down * ((m - i % mod) % mod) % mod;
	}
	return up * QP(down, mod - 2) % mod;
}

int main(){
	scanf("%d%lld", &n, &s);
	for(int i = 0 ; i < n ; ++ i)scanf("%lld", &f[i]);
	for(int i = 0 ; i < (1 << n) ; ++ i){
		int bits = 0;
		ll sum = s;
		for(int j = 0 ; j < n ; ++ j){
			if(i & (1 << j))sum -= f[j] + 1, ++ bits;	
		}
		//printf("%lld %d\n", sum+n-1, n-1);
		if(bits & 1)ans = (ans - C(sum + n - 1, n - 1) + mod) % mod;
		else ans = (ans + C(sum + n - 1, n - 1)) % mod;
		
	}
	printf("%lld\n", ans);
	return 0;
}

