#include <stdio.h>
#include <stack>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, a[maxn], l[maxn], r[maxn];
ll sum[maxn];
stack<int> sta;

inline ll max(ll a, ll b){return a > b ? a : b;}

void solve(){
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	a[0] = a[n+1] = -1;
	ll ans = -1;
	int ansl, ansr;
	while(!sta.empty())sta.pop();
	sta.push(0);
	for(int i = 1 ; i <= n ; ++ i){
		while(a[sta.top()] >= a[i])sta.pop();
		l[i] = sta.top() + 1;
		sta.push(i);
	}
	while(!sta.empty())sta.pop();
	sta.push(n+1);
	for(int i = n ; i >= 1 ; -- i){
		while(a[sta.top()] >= a[i])sta.pop();
		r[i] = sta.top() - 1;
		sta.push(i);
	}
	for(int i = 1 ; i <= n ; ++ i){
		ll tmp = (sum[r[i]] - sum[l[i] - 1]) * (ll)a[i];
		if(tmp > ans)ans = tmp, ansl = l[i], ansr = r[i];
	}
	printf("%lld\n%d %d\n", ans, ansl, ansr);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}


