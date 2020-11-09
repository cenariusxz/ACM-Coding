#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int n, m, bit[10], nxt[10];
vector<int> V[34];
ll dp[maxn][34];

void dfs(int t, int id){
	if(t == m-1){
		int tmp = 0;
		for(int i = 0 ; i < m ; ++ i)tmp = tmp * 2 + nxt[i];
		V[id].PB(tmp);
		return;
	}
	if(bit[t+1] == 1){
		nxt[t+1] = 0;
		dfs(t+1, id);
		return;
	}
	nxt[t+1] = 0;
	dfs(t+1, id);
	if(t+2 < m && bit[t+2] == 0){
		nxt[t+1] = nxt[t+2] = 1;
		dfs(t+2, id);
		nxt[t+1] = nxt[t+2] = 0;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < (1 << m) ; ++ i){
		for(int p = 0 ; p < m ; ++ p){
			if(i & (1 << p))bit[p] = 1;
			else bit[p] = 0;
		}
		dfs(-1, i);
	}
	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 0 ; j < (1 << m) ; ++ j){
			for(int k = 0 ; k < V[j].size() ; ++ k){
				int p = V[j][k];
				dp[i][j] += dp[i-1][p];
				dp[i][j] %= mod;
			}
		}
	}
	printf("%lld\n", dp[n][0]);
    return 0;
}
