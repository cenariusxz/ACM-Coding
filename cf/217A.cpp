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

int n, x[maxn], y[maxn], vis[maxn];

void dfs(int s){
	vis[s] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		if(x[s] == x[i] || y[s] == y[i])dfs(i);
	}
}

void solve(){
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		dfs(i);
		cnt ++;
	}
	printf("%d\n", cnt-1);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &x[i], &y[i]);
	solve();
	return 0;
}

