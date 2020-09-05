#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e6 + 5;

int n, dp[maxn];
vector<int> V[maxn];

void dfs(int s, int f){
	dp[s] = 0;
	int flag = 0;
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		if(j == f)continue;
		dfs(j, s);
		dp[s] += max(1, dp[j]);
		if(dp[j])flag = 1;
	}
	if(!flag)dp[s] = max(0, dp[s] - 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	dfs(1, -1);
	printf("%d\n", max(1, dp[1]));
	return 0;
}

