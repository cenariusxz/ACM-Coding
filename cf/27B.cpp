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

int n;
vector<int>V[maxn]; 
int cnt[maxn], vis[maxn];

void dfs(int s){
	vis[s] = 1;
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		if(vis[j])continue;
		dfs(j);
	}
}

void solve(){
	int a = 0, b = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(cnt[i] == n-1)continue;
		if(a)b = i;
		else a = i;
	}
	memset(vis, 0, sizeof(vis));
	dfs(a);
	if(vis[b])printf("%d %d\n", a, b);
	else printf("%d %d\n", b, a);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n*(n-1)/2-1 ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		cnt[a] ++;
		cnt[b] ++;
	}
	solve();
	return 0;
}

