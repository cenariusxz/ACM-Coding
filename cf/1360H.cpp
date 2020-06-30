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

int n, m;
char s[maxn];
ll num[105];

ll max(ll a, ll b){return a > b ? a : b;}

void solve(){
	scanf("%d%d", &n, &m);
	memset(num, 0, sizeof(num));
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s", s);
		for(int j = 0 ; s[j] ; ++ j)num[i] = (num[i]<<1) + s[j] - '0';
	}
	ll k = (1ll << m) - n;
	ll x = (k - 1) >> 1;	// 比mid小的有x个 的 最大值 
	ll l = 0, r = (1ll << m) - 1, ans = -1;
	while(l <= r){
		ll mid = (l + r) >> 1;
		ll sum = mid;
		for(int i = 1 ; i <= n ; ++ i)sum -= (num[i] < mid);
		if(sum <= x)ans = max(ans, mid), l = mid + 1;
		else r = mid - 1;
	}
	//printf("%lld\n", ans);
	for(int i = m - 1 ; i >= 0 ; -- i){
		s[i] = (ans & 1) + '0';
		ans >>= 1;
	}
	printf("%s\n", s);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

