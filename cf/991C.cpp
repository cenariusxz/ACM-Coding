#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

ll n;

ll min(ll a, ll b){return a < b ? a : b;}

bool check(ll x){
	ll sum = 0, tmp = n;
	while(tmp){
		if(tmp >= x)sum += x, tmp -= x;
		else{
			sum += tmp;
			tmp = 0;
		}
		if(tmp >= 10)tmp -= tmp / 10;
	}
	return sum + sum >= n;
}

void solve(){
	ll l = 1, r = n, ans = INF;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid))ans = min(ans, mid), r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%lld", &n);
	solve();
	return 0;
}

