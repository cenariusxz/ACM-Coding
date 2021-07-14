#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 1e6 + 6;

ll A[maxn+5], AA[maxn+5];

ll QP(ll a, ll n){
	ll ans = 1, tmp = a;
	while(n){
		if(n & 1)ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}

void init(){
	A[0] = 1;
	for(int i = 1 ; i <= maxn ; ++ i)A[i] = A[i-1] * i % mod;
	AA[maxn] = QP(A[maxn], mod - 2);
	for(int i = maxn ; i >= 1 ; -- i)AA[i-1] = AA[i] * i % mod;
}

ll C(int n, int m){
	return A[n] * AA[n-m] % mod * AA[m] % mod;
}

int main(){
	init();
	ll n;
	scanf("%lld", &n);
	ll ans = (QP(3, n*n) - QP((QP(3, n) - 3 + mod) % mod , n) + mod) % mod;
	for(int i = 1 ; i <= n ; ++ i){
		ll tmp = C(n, i) * 
			(
				(
					3 * QP((QP(3, n-i) - 1 + mod) % mod, n) % mod 
					+ 
					(QP(3, i) - 3 + mod) % mod * QP(3, n * (n - i)) % mod
				) % mod
			) % mod;
		if(i & 1)ans = (ans + tmp) % mod;
		else ans = (ans - tmp + mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

