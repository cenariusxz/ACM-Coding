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

int n, k, w, ans, a[25], b[25];

void dfs(int t, int pre, int sv, int sw){
	if(t == k){
		if(sw <= w)ans = max(ans, sv);
		return;
	}
	if(t + n - pre < k)return;
	for(int i = pre + 1 ; i <= n ; ++ i){
		if(sw + b[i] > w)continue;
		dfs(t + 1, i, sv + a[i], sw + b[i]);
	}
}

void solve(){
	ans = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &a[i], &b[i]);
	scanf("%d", &w);
	dfs(0, 0, 0, 0);
	printf("%d\n", ans);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

