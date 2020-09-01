#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e3 + 5;
const int maxm = 1e6 + 5;

vector<int> V[maxn];
int a[maxn], vis[maxn];
int num[maxn], cnt, n, mn, k;
ll dp[maxn][2];

void dfs(int s, int f){
	dp[s][0] = dp[s][1] = 0;
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		if(j == f)continue;
		dfs(j, s);
	}
	if(!vis[s])return;
	ll sum = 1;
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		if(j == f)continue;
		sum *= (dp[j][0] + dp[j][1] + 1) % mod;
		sum %= mod;
	}
	if(a[s] == mn)dp[s][1] = sum;
	else{
		dp[s][0] = 1;
		for(int i = 0 ; i < V[s].size() ; ++ i){
			int j = V[s][i];
			if(j == f)continue;
			dp[s][0] *= (dp[j][0] + 1) % mod;
			dp[s][0] %= mod;
		}
		dp[s][1] = (sum - dp[s][0] + mod) % mod;
	}
}

void solve(){
	for(int i = 1 ; i <= n ; ++ i)num[i] = a[i];
	sort(num + 1, num + 1 + n);
	cnt = unique(num + 1, num + 1 + n) - (num + 1);
	ll ans = 0;
	for(int i = 1 ; i <= cnt ; ++ i){
		mn = num[i];
		for(int j = 1 ; j <= n ; ++ j)vis[j] = (a[j] >= mn && a[j] <= mn + k);
		dfs(1, -1);
		for(int j = 1 ; j <= n ; ++ j)ans = (ans + dp[j][1]) % mod;
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i < n ; ++ i){
		int s, t;
		scanf("%d%d", &s, &t);
		V[s].PB(t);
		V[t].PB(s);
	}
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

