#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n;
ll num[maxn], dp[maxn][2];

ll max(ll a, ll b){return a > b ? a : b;}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		num[a] += a;
	}
	for(int i = 1 ; i <= 100000 ; ++ i){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = dp[i-1][0] + num[i];
	}
	printf("%lld\n", max(dp[100000][0], dp[100000][1]));
	return 0;
}

