#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n;
int a[maxn], dp[maxn][2];

void solve(){
	a[0] = -INF;
	dp[1][0] = dp[1][1] = 1;
	int ans = 1;
	for(int i = 2 ; i <= n ; ++ i){
		if(a[i] > a[i-1])dp[i][0] = dp[i-1][0] + 1;
		else dp[i][0] = 1;
		
		if(a[i] > a[i-1])dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
		if(a[i] > a[i-2]+1)dp[i][1] = max(dp[i][1], dp[i-2][0] + 2);
		else dp[i][1] = max(dp[i][1], 2);
		
		ans = max(ans, max(dp[i-1][0] + 1, dp[i][1]));
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

