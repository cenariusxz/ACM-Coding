#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;

int dp[maxn],v[35];

int main(){
	int s,n;
	scanf("%d%d",&s,&n);
	memset(dp,0,sizeof(dp));
	for(int i = 1 ; i <= n ; ++i)scanf("%d",&v[i]);
	dp[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = s ; j >= v[i] ; --j){
			if(dp[j-v[i]])dp[j] = 1;
		}
	}
	for(int i = s ; i >= 0 ; --i){
		if(dp[i]){
			printf("%d\n",s-i);
			break;
		}
	}
	return 0;
}
