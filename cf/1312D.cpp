#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 998244353;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

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
    A[0]=1;
    for(int i=1;i<=maxn;++i)A[i]=A[i-1]*i%mod;
    AA[maxn]=QP(A[maxn],mod-2);
    for(int i=maxn;i>=1;--i)AA[i-1]=AA[i]*i%mod;
}

ll C(int n,int m){
	if(m > n)return 0;
    return A[n] * AA[n-m] % mod * AA[m] % mod;
}

int main(){
	init();
	ll n, m;
	scanf("%lld%lld", &n, &m);
	if(n <= 2)printf("0\n");
	else printf("%lld\n", C(m, n-1) * (n-2) % mod * QP(2, n-3) % mod);
	return 0;
}

