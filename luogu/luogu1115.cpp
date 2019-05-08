#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int a[maxn],dp[maxn];
int n,ans = -INF;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i)dp[i] = a[i] + max(dp[i-1], 0);
	for(int i = 1 ; i <= n ; ++ i)ans = max(ans, dp[i]);
	printf("%d\n",ans);
	return 0;
}

