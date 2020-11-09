#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6 + 35;
const int mod=998244353;

ll A[maxn+5],AA[maxn+5];        //A是阶乘数组，AA是阶乘逆元数组

ll QP(ll a,ll n){
    ll ans = 1 ,tmp = a;
    while(n){
        if(n&1)ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;;
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
    return A[n] * AA[n-m] % mod * AA[m] % mod;
}

int main(){
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	int lim = min(n, m);
	ll ans = 0;
	for(int i = 1 ; i <= lim ; ++ i){
		//printf("%lld %lld\n", C(m-1, i-1), C(n, i));
		ll res = C(m-1, i-1) * C(n, i) % mod;
		ans = (ans + res) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
