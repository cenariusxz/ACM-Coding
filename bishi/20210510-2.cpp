#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e5 + 5;

int n, m, d[maxn], res;
vector<int> V[2][maxn];

void dfs(int id, int s, int f){
	if(d[s] > d[res])res = s;
	for(int i = 0 ; i < V[id][s].size() ; ++ i){
		int j = V[id][s][i];
		if(j == f)continue;
		d[j] = d[s] + 1;
		dfs(id, j, s);
	}
}

int solve(int id){
	memset(d, -1, sizeof(d));
	res = 1;
	d[1] = 0;
	dfs(id, 1, -1);
	memset(d, -1, sizeof(d));
	d[res] = 0;
	dfs(id, res, -1);
	return d[res];
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		V[0][a].PB(b);
		V[0][b].PB(a);
	}
	scanf("%d", &m);
	for(int i = 1 ; i < m ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		V[1][a].PB(b);
		V[1][b].PB(a);
	}
	int len1 = solve(0), len2 = solve(1);
	int mx = max(max(len1, len2), (len1+1)/2 + (len2+1)/2 + 1);
	printf("%d\n", len1 + len2 + 1 - mx);
	return 0;
}

