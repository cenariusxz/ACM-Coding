#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

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
	int T;
	scanf("%d", &T);
	while(T--){
		ll p, q, k;
		scanf("%lld%lld%lld", &q, &p, &k);
		printf("%lld\n", 
			(QP(p, k) + QP(p-2*q, k)) % mod 
			* QP(2, mod-2) % mod 
			* QP(QP(p, k), mod-2) % mod
		);
	}
	return 0;
}

