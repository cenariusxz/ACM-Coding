#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e3 + 5;

int n,k;
int a[maxn],sum[maxn];
ll dp[maxn][maxn];

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1 ; i <= n ; ++ i){
		dp[i][0] = sum[i];
		for(int j = 1 ; j <= min(i-1,k) ; ++ j){
			for(int p = 1 ; p < i ; ++ p){
				if(~dp[p][j-1])dp[i][j] = max(dp[i][j], dp[p][j-1]*(sum[i] - sum[p]));
			}
		}
	}
	printf("%lld\n",dp[n][k]);
	return 0;
}
