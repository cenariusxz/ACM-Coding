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

int n, l[maxn], vis[maxn];

void solve(){
	sort(l + 1, l + 1 + n, greater<int>());
	ll b = 0, ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		if(l[i] == l[i+1] || l[i] - 1 == l[i+1]){
			if(b){
				ans += l[i+1] * b;
				b = 0;
			}
			else b = l[i+1];
			vis[i] = vis[i+1] = 1;
		}
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &l[i]);
	solve();
	return 0;
}

