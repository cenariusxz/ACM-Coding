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

ll a, b, c, l;

ll min(ll x, ll y){return x < y ? x : y;}

ll get(ll a, ll b, ll c){
	ll ans = 0;
	for(ll i = 0 ; i <= l ; ++ i){
		ll tmpa = a + i;
		if(b + c > tmpa)continue;
		ll tmpbc = min(l - i, tmpa - b - c);
		ans += (tmpbc + 2) * (tmpbc + 1) / 2;
	}
	return ans;
}

int main(){
	scanf("%lld%lld%lld%lld", &a, &b, &c, &l);
	ll ans = 0;
	for(ll i = 0 ; i <= l ; ++ i)ans += (i+2)*(i+1)/2;
	ans -= get(a, b, c);
	ans -= get(b, a, c);
	ans -= get(c, a, b);
	printf("%lld\n", ans);
	return 0;
}

