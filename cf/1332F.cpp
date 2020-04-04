#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 998244353;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 3e5 + 5;
const int maxm = maxn << 1;

ll dp[maxn][3];
// dp[s][0] - s子树，s未选 
// dp[s][1] - s子树，s被选 
// dp[s][2] - s子树，s未与任意子节点相连 
int head[maxn], point[maxm], nxt[maxm], size;
int n;

void init(){
	memset(head, -1, sizeof(head));
	size = 0;
}

void add(int a, int b){
	point[size] = b;
	nxt[size] = head[a];
	head[a] = size++;
}

void dfs(int s, int f){
	ll p0 = 0, p1 = 0, p2 = 0;
	// s 不与子节点相连合法种类数
	// 与 s 相连的子节点无选中点合法种类数
	// 与 s 相连的子结点有选中点合法种类数
	for(int i = head[s] ; ~ i ; i = nxt[i]){
		int t = point[i];
		if(t == f)continue;
		dfs(t, s);
		ll np0 = 0, np1 = 0, np2 = 0;
		np0 += (dp[t][0] + dp[t][1]) % mod;
		np0 += (dp[t][0] + dp[t][1] + 1) % mod * p0 % mod;
		np0 %= mod;
		np1 += (dp[t][0] + 1) % mod;
		np1 += (dp[t][0] + 1) % mod * p0 % mod;
		np1 += (dp[t][0] + 1 + dp[t][0] + dp[t][1] + 1) % mod * p1 % mod; 
		np1 %= mod;
		np2 += (dp[t][1] + dp[t][2] + 1) % mod;
		np2 += (dp[t][1] + dp[t][2] + 1) % mod * p0 % mod;
		np2 += (dp[t][1] + dp[t][2] + 1) % mod * p1 % mod;
		np2 += (dp[t][0] + dp[t][1] + 1 + dp[t][0] + dp[t][1] + 1 + dp[t][2] + 1) % mod * p2 % mod;
		np2 %= mod;
		p0 = np0;
		p1 = np1;
		p2 = np2;
	}
	dp[s][0] = (p0 + p1 + p2) % mod;
	dp[s][1] = p1;
	dp[s][2] = p0;
}

int main(){
	init();
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d",&a,&b);
		add(a, b); add(b, a);
	}
	dfs(1, -1);
	printf("%lld\n", (dp[1][0] + dp[1][1]) % mod);
	return 0;
}
