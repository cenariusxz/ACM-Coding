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

int m, p, q;

ll QP(ll a,ll n){
    ll tmp=a,ans=1;
    while(n){
        if(n&1)ans=ans*tmp%mod;
        tmp=tmp*tmp%mod;
        n>>=1;
    }
    return ans;
}

ll gcd(ll a, ll b){
	return b ? gcd(b, a%b) : a;	
}

inline ll abs(ll a){return a > 0 ? a : -a;}

ll solve(){
	ll up = (ll)100 * p * m + p * q - (ll)100 * m * q, down = (ll)100 * p;
	
	ll g = gcd(up, down);
	//printf("%lld %lld %lld\n", up, down, g);
	up /= g; down /= g;
	up %= mod; down %= mod;
	return (up * QP(down, mod-2) % mod + mod) % mod;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &m, &p, &q);
		printf("%lld\n", solve());
	}
	return 0;
}

