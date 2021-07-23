#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n, k, a[maxn];
ll A[maxn+5], AA[maxn+5], sum[maxn+5], pw10[maxn+5];

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
	AA[maxn] = QP(A[maxn], mod-2);
	for(int i = maxn ; i >= 1 ; -- i)AA[i-1] = AA[i] * i % mod;
	pw10[0] = 1;
	for(int i = 1 ; i <= maxn ; ++ i)pw10[i] = pw10[i-1] * 10 % mod;
}

ll C(int n, int m){
	if(n < m)return 0;
	return A[n] * AA[n-m] % mod * AA[m] % mod;
}

int main(){
	init();
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%1d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	ll ans = 0;
	for(int i = 1 ; i <= n-k ; ++ i){
		ans = (ans + C(n - 1 - i, k - 1) * pw10[i-1] % mod * sum[n-i] % mod) % mod;
		ans = (ans + C(n-i, k) * a[n-i+1] % mod * pw10[i-1] % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

