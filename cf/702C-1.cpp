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

int n, m;
ll a[maxn], b[maxn];

ll bsearchl(ll x){
	int l = 0, r = m+1, ans = 0;
	while(l <= r){
		int mid = l + ((r-l) >> 1);
		if(b[mid] <= x)ans = max(ans, mid), l = mid + 1;
		else r = mid - 1;
	}
	return b[ans];
}

ll bsearchr(ll x){
	int l = 0, r = m+1, ans = m+1;
	while(l <= r){
		int mid = l + ((r-l) >> 1);
		if(b[mid] >= x)ans = min(ans, mid), r = mid - 1;
		else l = mid + 1;
	}
	return b[ans];
}

void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	for(int i = 1 ; i <= m ; ++ i)scanf("%lld", &b[i]);
	b[0] = -INF, b[m+1] = INF;
	ll ans = -INF;
	for(int i = 1 ; i <= n ; ++ i){
		ll left = bsearchl(a[i]);
		ll right = bsearchr(a[i]);
		ll res = min(a[i] - left, right - a[i]);
		ans = max(ans, res);
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%d%d", &n, &m);
	solve();
	return 0;
}


