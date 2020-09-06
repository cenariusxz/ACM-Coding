#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

int n, a[maxn], l[maxn], r[maxn];
stack<int> sta;

inline ll max(ll a, ll b){return a > b ? a : b;}

void solve(){
	a[0] = INF;
	sta.push(0);
	for(int i = 1 ; i <= n ; ++ i){
		while(a[sta.top()] <= a[i])sta.pop();
		l[i] = sta.top();
		sta.push(i);
	}
	while(!sta.empty())sta.pop();
	sta.push(0);
	for(int i = n ; i >= 1 ; -- i){
		while(a[sta.top()] <= a[i])sta.pop();
		r[i] = sta.top();
		sta.push(i);
	}
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i)ans = max(ans, l[i] * (ll)r[i]);
	printf("%lld\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

