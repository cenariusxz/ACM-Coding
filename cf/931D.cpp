#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n, dep[maxn], cnt[maxn];
vector<int> V[maxn];

void dfs(int s, int d){
	cnt[d]++;
	for(int i = 0 ; i < V[s].size() ; ++ i){
		dfs(V[s][i], d+1);
	}
}

void solve(){
	dfs(1, 1);
	int ans = 0;
	for(int i = 1 ; i <= 100000 ; ++ i)ans += cnt[i] % 2;
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 2 ; i <= n ; ++ i){
		int fa;
		scanf("%d", &fa);
		V[fa].PB(i);
	}
	solve();
	return 0;
}


