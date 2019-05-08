#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 5;

int dp[maxn],w[35],v[35];

int main(){
	int t,m;
	while(scanf("%d%d",&t,&m)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i = 1 ; i <= m ; ++i)scanf("%d%d",&w[i],&v[i]);
		for(int i = 1 ; i <= m ; ++i)v[i] *= w[i];
		int ans = 0;
		for(int i = 1 ; i <= m ; ++i){
			for(int j = t ; j >= w[i] ; --j){
				dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
				ans = max(ans, dp[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
