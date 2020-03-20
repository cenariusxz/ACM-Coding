#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 805;
const int maxm = 1e6 + 5;

ll a[maxn][maxn], b[maxn][maxn];
ll dp[maxn][2];
ll sum[maxn];
int n,m;

ll solve(ll a[][maxn], int n, int m){
	for(int i = 1 ; i <= n ; ++ i){
		sum[i] = 0;
		for(int j = 1 ; j <= m ; ++ j)sum[i] += a[i][j];
	}
	dp[1][0] = a[1][1];
	dp[1][1] = sum[1];
	for(int i = 2 ; i <= n ; ++ i){
		dp[i][0] = max(dp[i-1][0] + a[i][1], dp[i-1][1] + sum[i]);
		dp[i][1] = max(dp[i-1][1] + a[i][m], dp[i-1][0] + sum[i]);
	}
	//printf("%lld\n",dp[3][0]);
	return dp[n][1];
}

int main(){
	scanf("%d%d",&n,&m);
	ll sum = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%lld", &a[i][j]);
			b[j][i] = a[i][j];
			if(a[i][j] > 0)sum += a[i][j];
		}
	}
	//printf("%lld\n",sum);
	printf("%lld\n", max(solve(a, n, m), solve(b, m, n)));
	return 0;
}

