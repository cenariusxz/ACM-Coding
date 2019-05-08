#include <bits/stdc++.h>
using namespace std;

int dp[1005],w[105],v[105];

int main(){
	int t,m;
	scanf("%d%d",&t,&m);
	for(int i = 1 ; i <= m ; ++i)scanf("%d%d",&v[i],&w[i]);
	for(int i = 1 ; i <= m ; ++i){
		for(int j = t ; j >= v[i] ; --j){
			dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
		}
	}
	printf("%d\n",dp[t]);
	return 0;
}
