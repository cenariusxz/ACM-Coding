#include <stdio.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 9901;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int A,B;
int a[105],p[105];

ll QM(ll x, ll y, ll mod){
    ll ans = 0, tmp = x;
    while(y){
        if(y&1)ans = (ans + tmp) % mod;
        tmp = (tmp << 1) % mod;
		y >>= 1;
    }
    return ans;
}

ll QP(ll a, ll n, ll mod){
	ll ans = 1, tmp = a;
	while(n){
		if(n&1)ans = QM(ans, tmp, mod);
		tmp = QM(tmp, tmp, mod);
		n >>= 1;
	}
	return ans;
}

void solve(){
	int cnt = 0;
	for(int i = 2 ; i * i <= A ; ++ i){
		if(A % i == 0){
			a[++cnt] = i;
			while(A % i == 0){
				p[cnt] ++;
				A /= i;
			}
		}
	}
	if(A != 1){
		a[++cnt] = A;
		p[cnt] ++;
	}
	ll ans = 1;
	for(int i = 1 ; i <= cnt ; ++ i){
		// ( [(a[i] ^ (p[i]*B+1)) - 1] / [ a[i] - 1 ] ) % mod 
		ll m = mod * (ll)(a[i]-1);
		ll P = QP(a[i], p[i]*(ll)B + 1, m) - 1 + m;
		ans *= P/(a[i] - 1)%mod;
		ans %= mod;
	}
	printf("%lld\n",ans);
}

int main(){
	scanf("%d%d",&A,&B);
	if(A == 0)printf("0\n");
	else if(B == 0)printf("1\n");
	else solve();
	return 0;
}

