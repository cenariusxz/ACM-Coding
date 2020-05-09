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
int c[maxn], vis[maxn];
vector<int>V[maxn];

int dfs(int s){
	vis[s] = 1;
	int res = c[s];
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		if(vis[j])continue;
		res = min(res, dfs(j));
	}
	return res;
}

void solve(){
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		ans += dfs(i);
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &c[i]);
	while(m --){
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	solve();
	return 0;
}

