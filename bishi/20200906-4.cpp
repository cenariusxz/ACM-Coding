#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

stack<int> sta;
int n, w, a[maxn];

ll solve(){
	for(int i = 1 ; i <= n ; ++ i)a[i] = w - a[i];
	for(int i = 1 ; i <= n ; ++ i)if(a[i] < 0 || abs(a[i] - a[i-1]) > 1)return 0;
	ll ans = 1;
	sta.push(0);
	for(int i = 1 ; i <= n ; ++ i){
		int top = sta.top();
		if(a[i] == top + 1)sta.push(a[i]);
		else if(a[i] == top)ans = ans * (a[i] + 1) % mod;
		else ans = ans * (a[i] + 1) % mod, sta.pop();
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &w);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	printf("%lld\n", solve());
	return 0;
}

