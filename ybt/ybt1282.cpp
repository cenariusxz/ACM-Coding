#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e2 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int a[maxn][maxn],dp[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			scanf("%d",&a[i][j]);
		}
	}
	int ans = -INF;
	for(int up = 1 ; up <= n ; ++ up){
		for(int down = up ; down <= n ; ++ down){
			for(int i = 1 ; i <= n ; ++ i){
				dp[i] = 0;
				for(int j = up ; j <= down ; ++ j)dp[i] += a[j][i];
				if(dp[i-1] > 0)dp[i] += dp[i-1];
				if(dp[i] > ans)ans = dp[i];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

