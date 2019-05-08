#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int n,k;
int dp[105],m[105],p[105];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&m[i]);
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&p[i]);
		m[0] = -INF;
		memset(dp,0,sizeof(dp));
		for(int i = 1 ; i <= n ; ++ i){
			for(int j = 0 ; j < i ; ++ j){
				if(m[i] - m[j] > k)dp[i] = max(dp[i], dp[j] + p[i]);
			}
		}
		int ans = 0;
		for(int i = 1 ; i <= n ; ++ i)ans = max(ans, dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}

