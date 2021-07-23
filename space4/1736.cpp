#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 9;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

ll n, k, a, b;
char s[maxn];

ll QP(ll a, ll n){
	ll ans = 1, tmp = a;
	while(n){
		if(n & 1)ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}

int main(){
	scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
	scanf("%s", s);
	ll t = (n+1) / k;
	ll A = QP(a, k), B = QP(b, k);
	ll sum = 0;
	if(A * QP(B, mod-2) % mod == 1)sum = QP(a, n) * t % mod;
	else sum = QP(a, n) 
			* ((QP(A, t) - QP(B, t) + mod) % mod) % mod 
			* QP(QP(A, t-1), mod-2) % mod
			* QP((A - B + mod) % mod, mod-2) % mod;
	// printf("%lld\n", QP(b * QP(a, mod-2) % mod, k) );
	// printf("%lld\n", A * QP(B, mod-2) % mod);
	// printf("%lld %lld\n", A, B);
	// printf("%lld %lld %lld %lld\n", k, t, A, B);
	// printf("%lld\n", ((QP(A, t) - QP(B, t) + mod) % mod) );
	ll ans = 0;
	for(ll i = 0 ; i < k ; ++ i){
		ll tmp = QP(b, i) * QP(QP(a, i), mod-2) % mod;
		if(s[i] == '+')ans = (ans + tmp) % mod;
		else ans = (ans - tmp + mod) % mod;
		// printf("%d : %lld\n", i, tmp * sum % mod);
	}
	printf("%lld\n", ans * sum % mod);
	return 0;
}

