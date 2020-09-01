#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e5 + 5;

int n, s, t;
int dis[2][maxn];
vector<int> V[maxn];

void dfs(int s, int f, int d, int c){
	dis[c][s] = d;
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		if(j == f)continue;
		dfs(j, s, d+1, c);
	}
}

int main(){
	scanf("%d%d%d", &n, &s, &t);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	dfs(s, -1, 0, 0);
	dfs(t, -1, 0, 1);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(dis[0][i] > dis[1][i]){
			ans = max(ans, dis[0][i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

