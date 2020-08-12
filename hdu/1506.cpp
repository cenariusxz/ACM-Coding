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

int n, h[maxn], l[maxn], r[maxn];
stack<int> sta;

inline ll max(ll a, ll b){return a > b ? a : b;}

void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &h[i]);
	h[0] = h[n+1] = -1;
	ll ans = 0;
	while(!sta.empty())sta.pop();
	sta.push(0);
	for(int i = 1 ; i <= n ; ++ i){
		while(h[sta.top()] >= h[i])sta.pop();
		l[i] = sta.top() + 1;
		sta.push(i);
	}
	while(!sta.empty())sta.pop();
	sta.push(n+1);
	for(int i = n ; i >= 1 ; -- i){
		while(h[sta.top()] >= h[i])sta.pop();
		r[i] = sta.top() - 1;
		sta.push(i);
	}
	for(int i = 1 ; i <= n ; ++ i)ans = max(ans, (r[i] - l[i] + 1) * (ll)h[i]);
	printf("%lld\n", ans);
}

int main(){
	while(scanf("%d", &n) && n)solve();
	return 0;
}

