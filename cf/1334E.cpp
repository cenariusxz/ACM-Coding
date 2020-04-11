#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 998244353;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

ll p[maxn], D, A[maxn], AA[maxn];
int pn[maxn], pv[maxn], pu[maxn], cnt;

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
    A[0] = 1;
    for(int i = 1 ; i <= 100000 ; ++ i)A[i] = A[i-1] * i % mod;
    AA[100000] = QP(A[100000], mod-2);
    for(int i = 100000 ; i >= 1 ; -- i)AA[i-1] = AA[i] * i % mod;
	cnt = 0;
	for(ll i = 2 ; i <= D / i ; ++ i){
		if(D % i == 0){
			p[++cnt] = i;
			while(D % i == 0)D /= i, pn[cnt] ++;
		}
	}
	if(D != 1){
		p[++cnt] = D;
		pn[cnt] = 1;
	}
}

void solve(){
	ll u, v, ans = 1;
	scanf("%lld%lld", &u, &v);
	int sum1 = 0, sum2 = 0;
	for(int i = 1 ; i <= cnt ; ++ i){
		pu[i] = pv[i] = 0;
		while(u % p[i] == 0)u /= p[i], pu[i]++;
		while(v % p[i] == 0)v /= p[i], pv[i]++;
	}
	
	for(int i = 1 ; i <= cnt ; ++ i){
		if(pu[i] > pv[i])sum1 += pu[i]-pv[i];
		if(pu[i] < pv[i])sum2 += pv[i]-pu[i];
	}
	ans = ans * A[sum1] % mod * A[sum2] % mod;
	for(int i = 1 ; i <= cnt ; ++ i){
		if(pu[i] > pv[i])ans = ans * AA[pu[i]-pv[i]] % mod;
		if(pu[i] < pv[i])ans = ans * AA[pv[i]-pu[i]] % mod;
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%lld", &D);
	init();
	int q;
	scanf("%d", &q);
	while(q--)solve();
	return 0;
}

