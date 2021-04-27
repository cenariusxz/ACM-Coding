#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

int n, T;

int a[505], head[505], point[1005], nxt[1005], val[1005], size;
ll dp[2][505][405];

void add(int a, int b, int v){
	val[size] = v;
	point[size] = b;
	nxt[size] = head[a];
	head[a] = size++;
}

void init(){
	size = 0;
	memset(head, -1, sizeof(head));
}

void dfs(int s, int f){
	if(a[s] > 0)for(int t = 0 ; t <= T ; ++ t)dp[0][s][t] = a[s];
	for(int i = head[s] ; ~i ; i = nxt[i]){
		int j = point[i];
		if(j == f)continue;
		dfs(j, s);
		for(int t = 0 ; t <= T ; ++ t){
			for(int k = 0 ; t + k + val[i] <= T ; ++ k){
				dp[1][s][t+k+val[i]] = max(dp[1][s][t+k+val[i]], dp[0][s][t] + dp[0][j][k]);
			}
		}
		for(int t = 0 ; t <= T ; ++ t)dp[0][s][t] = max(dp[0][s][t], dp[1][s][t]);
	}
}

int main(){
	scanf("%d%d", &n, &T);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	init();
	for(int i = 1 ; i < n ; ++ i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	memset(dp, 0, sizeof(dp));
	dfs(1, -1);
	printf("%lld\n", dp[0][1][T/2]);
	return 0;
}

