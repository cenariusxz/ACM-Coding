#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

ll n,b;
ll prime[20], pnum[20], pcnt;

int main(){
	scanf("%lld%lld", &n, &b);
	for(ll i = 2 ; b/i >= i ; ++ i){
		if(b % i == 0){
			prime[++pcnt] = i;
			while(b % i == 0){
				pnum[pcnt] ++;
				b /= i;
			}
		}
	}
	if(b > 1){
		prime[++pcnt] = b;
		pnum[pcnt] = 1;
	}
	ll ans = INF;
	for(int i = 1 ; i <= pcnt ; ++ i){
		ll cnt = 0;
		for(ll j = prime[i] ; j <= n ; j *= prime[i]){
			cnt += n / j;
			if(j > n / prime[i])break;
		}
		ans = min(ans, cnt/pnum[i]);
	}
	printf("%lld\n", ans);
	return 0;
}

