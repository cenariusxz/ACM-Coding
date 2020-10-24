#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 5e5 + 5;

int n;
int a[maxn], dp[2][2][maxn];
vector<int> v[maxn];

void dfs(int s, int f){
	int cnt = 0;
	for(int i = 0 ; i < v[s].size() ; ++ i){
		int j = v[s][i];
		if(j == f)continue;
		dfs(j, s);
		cnt ++;
	}
	if(!cnt){
		dp[0][a[s]][s] = 1;
		dp[1][a[s]^1][s] = 1;
		return;
	}
	int c0 = 0, c1 = 0, c2 = 0;
	for(int i = 0 ; i < v[s].size() ; ++ i){
		int j = v[s][i];
		if(j == f)continue;
		if(dp[0][1][j] == 1 && dp[1][1][j] == 0)c0 ++;
		if(dp[0][1][j] == 0 && dp[1][1][j] == 1)c1 ++;
		if(dp[0][1][j] == 1 && dp[1][1][j] == 1)c2 ++;
	}
	if(c0 + c1 + c2 == cnt){
		if(c2)dp[0][0][s] = dp[0][1][s] = 1;
		else dp[0][(a[s] + c1) & 1][s] = 1;
	}
	c0 = 0, c1 = 0, c2 = 0;
	for(int i = 0 ; i < v[s].size() ; ++ i){
		int j = v[s][i];
		if(j == f)continue;
		if(dp[0][0][j] == 1 && dp[1][0][j] == 0)c0 ++;
		if(dp[0][0][j] == 0 && dp[1][0][j] == 1)c1 ++;
		if(dp[0][0][j] == 1 && dp[1][0][j] == 1)c2 ++;
	}
	if(c0 + c1 + c2 == cnt){
		if(c2)dp[1][0][s] = dp[1][1][s] = 1;
		else dp[1][(a[s] + c1 + 1) & 1][s] = 1;
	}
}

void solve(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)v[i].clear();
	memset(dp, 0, sizeof(dp));
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].PB(b);
		v[b].PB(a);
	}
	dfs(1, -1);
	if(dp[0][1][1] || dp[1][1][1])printf("YES\n");
	else printf("NO\n");
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

