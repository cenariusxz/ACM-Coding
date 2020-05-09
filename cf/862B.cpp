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

int n, col[2];
vector<int>V[maxn];

void dfs(int s, int f, int c){
	col[c] ++;
	for(int i = 0 ; i < V[s].size(); ++ i){
		int j = V[s][i];
		if(j == f)continue;
		dfs(j, s, c^1);
	}
}

void solve(){
	dfs(1, -1, 0);
	printf("%lld\n", col[0] * (ll)col[1] - (n-1));
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	solve();
	return 0;
}

