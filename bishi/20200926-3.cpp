#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 6;

int n, k, a[maxn], dp[2][maxn][105], size[maxn];
vector<int> V[maxn];

void dfs(int s, int f){
	size[s] = 1;
	dp[s][0] = 0;
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		if(j == f)continue;
		dfs(j, s);
		size[s] += size[j];
		for(int num = 1 ; num <= size[j] ; ++ num){
			for(int pre = 0 ; pre + num <= size[s] ; ++ pre){
				
			}
		}
	}
}


int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		for(int i = 1 ; i <= n ; ++ i )scanf("%d", &a[i]);
		for(int i = 1 ; i <= n ; ++ i )V[i].clear();
		for(int i = 1 ; i < n ; ++ i){
			int a, b;
			scanf("%d%d", &a, &b);
			V[a].PB(b);
			V[b].PB(a);
		}
		memset(dp, -1, sizeof(dp));
		dfs(1. -1);
	}
	return 0;
}

