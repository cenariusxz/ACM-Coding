#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e6 + 5;
const int maxm = 1e6 + 5;

int x, y;
int p[10], np[10], cnt;
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
    return A[n] * AA[n-m] % mod * AA[m] % mod;
}

ll solve(){
	cnt = 0;
	for(int i = 2 ; i * (ll)i <= x ; ++ i){
		if(x % i == 0){
			p[++cnt] = i;
			np[cnt] = 0;
			while(x % i == 0){
				np[cnt] ++;
				x /= i;
			}
		}
	}
	if(x != 1){
		p[++cnt] = x;
		np[cnt] = 1;
	}
	ll ans = 1;
	for(int i = 1 ; i <= cnt ; ++ i){
		ans = ans * C(np[i] + y - 1, np[i]) % mod;
	}
	ans = ans * QP(2, y-1) % mod;
	return ans;
}

int main(){
	init();
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &x, &y);
		printf("%lld\n", solve());
	}
	return 0;
}

