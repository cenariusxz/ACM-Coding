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

ll n, m, k;

ll max(ll a, ll b){return a > b ? a : b;}

ll cal(ll st, ll num){
	ll ed = st - num + 1;
	if(ed > 0)return (ed + st) * num / 2;
	else return (1 + st) * st / 2 + num - st;
}

bool check(ll x){
	ll low = cal(x-1, k-1) + cal(x-1, n-k);
	return x + low <= m;
}

void solve(){
	ll l = m/n, r = m, ans = m/n;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid))ans = max(ans, mid), l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%lld%lld%lld", &n, &m, &k);
	solve();
	return 0;
}

