#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 998244353;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e6 + 5;
const int maxm = 1e6 + 5;

int n, m;
ll p[maxn], like[maxn];

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
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i){
		int k;
		scanf("%d", &k);
		for(int j = 1 ; j <= k ; ++ j){
			int a;
			scanf("%d", &a);
			m = max(m, a);
			like[a] ++;
			p[a] = (p[a] + 1 * QP(n, mod-2) % mod * QP(k, mod-2) % mod) % mod;		// 1/n * 1/k
		}
	}
	ll ans = 0;
	for(int i = 1 ; i <= m ; ++ i)ans = (ans + p[i] * like[i] % mod * QP(n, mod-2) % mod) % mod;
	printf("%lld\n", ans);
	return 0;
}

