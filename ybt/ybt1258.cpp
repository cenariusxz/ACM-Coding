#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int n,ans = 0;
int a[maxn][maxn];
int dp[maxn][maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= i ; ++ j){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= i ; ++ j){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}

