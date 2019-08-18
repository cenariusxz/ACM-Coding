#include <stdio.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int mod;

ll QP(ll a,ll n){
	ll ans = 1, tmp = a;
	while(n){
		if(n&1)ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d%d",&mod,&n);
		ll ans = 0;
		while(n--){
			ll a,b;
			scanf("%lld%lld",&a,&b);
			a %= mod;
			ans = (ans + QP(a,b)) % mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

