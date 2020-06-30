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

ll n, k; 

void solve(){
	ll l = 1, r = n;
	while(l <= r){
		ll mid = (l + r) >> 1;
		ll num = (mid * mid + 3 * mid) / 2;
		if(num == n + k){
			printf("%lld\n", n - mid);
			return;
		}
		if(num < n + k)l = mid + 1;
		else r = mid - 1;
	}
}

int main(){
	scanf("%lld%lld", &n, &k);
	solve();
	return 0;
}

