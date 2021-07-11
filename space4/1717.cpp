#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 998244353;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

ll A[maxn], ans;
int n;
vector<int> G[maxn];

void init(){
	A[1] = 1;
	for(int i = 2 ; i <= 200000 ; ++ i)A[i] = A[i-1] * i % mod;
}

void dfs(int s, int f){
	int son = 0;
	for(int i = 0 ; i < G[s].size() ; ++ i){
		if(G[s][i] != f){
			++ son;
			dfs(G[s][i], s);
		}
	}
	ans = ans * A[son+1] % mod;
}

int main(){
	init();
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].PB(b);
		G[b].PB(a);
	}
	ans = n;
	int son = 0;
	for(int i = 0 ; i < G[1].size() ; ++ i){
		++ son;
		dfs(G[1][i], 1);
	}
	ans = ans * A[son] % mod;
	printf("%lld\n", ans);
	return 0;
}

