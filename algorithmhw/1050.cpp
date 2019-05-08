#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 105;

int a[maxn][maxn];
int sum[maxn][maxn];
int dp[maxn];
int n;

int solve(int l, int r){
	int ans = -INF;
	for(int i = 1 ; i <= n ; ++ i){
		dp[i] = sum[r][i] - sum[l-1][i];
		if(dp[i-1] > 0)dp[i] += dp[i-1];
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			scanf("%d",&a[i][j]);
			sum[i][j] = sum[i-1][j] + a[i][j];
		}
	}
	int ans = -INF;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = i ; j <= n ; ++ j){
			ans = max(ans, solve(i,j));
		}
	}
	printf("%d\n",ans);
	return 0;
}
