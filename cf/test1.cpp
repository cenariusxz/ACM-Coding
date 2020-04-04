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

ll dp[maxn][2][2];
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
	dp[s][0][0] = dp[s][0][1] = dp[s][1][0] = dp[s][1][1] = 1;
	ll iso = 1;
	for(int i = head[s] ; ~i ; i = nxt[i]){
		int t = point[i];
		if(t == f)continue;
		dfs(t, s);
		ll sum = dp[t][0][0] + dp[t][0][1] + dp[t][1][0] + dp[t][1][1];
		dp[s][0][0] *= sum;
		dp[s][0][0] %= mod;
		dp[s][0][1] *= sum;
		dp[s][0][1] %= mod;
		dp[s][1][0] *= (sum - dp[t][1][1]);
		dp[s][1][0] %= mod;
		dp[s][1][1] *= (sum - dp[t][1][1]);
		dp[s][1][1] %= mod;
		iso *= (dp[t][0][0] + dp[t][1][0]);
		iso %= mod;
	}
	printf("%d : dp[0][0]:%lld dp[0][1]:%lld dp[1][0]:%lld dp[1][1]:%lld\n", s, dp[s][0][0], dp[s][0][1], dp[s][1][0], dp[s][1][1]);
	printf("iso: %lld\n", iso);
	dp[s][0][0] = (((dp[s][0][0] - iso) % mod) + mod) % mod;
	printf("%d : dp[0][0]:%lld dp[0][1]:%lld dp[1][0]:%lld dp[1][1]:%lld\n", s, dp[s][0][0], dp[s][0][1], dp[s][1][0], dp[s][1][1]);
	
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
	printf("%lld\n", (dp[1][0][0] + dp[1][1][0] - 1 + mod) % mod);
	return 0;
}
