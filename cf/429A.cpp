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

int n, init[maxn], goal[maxn];
vector<int>V[maxn];
int ans[maxn], cnt;

void dfs(int s, int f, int n1, int n2){
	init[s] ^= n1;
	if(init[s] != goal[s]){
		ans[++cnt] = s;
		n1 ^= 1;
		init[s] ^= 1;
	}
	for(int i = 0 ; i < V[s].size(); ++ i){
		int j = V[s][i];
		if(j == f)continue;
		dfs(j, s, n2, n1);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &init[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &goal[i]);
	dfs(1, -1, 0, 0);
	printf("%d\n", cnt);
	for(int i = 1 ; i <= cnt ; ++ i)printf("%d\n", ans[i]);
	return 0;
}

