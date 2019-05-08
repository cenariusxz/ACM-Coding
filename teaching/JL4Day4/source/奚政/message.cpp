#include <bits/stdc++.h>
using namespace std;
const int mod = 10000;

int dp[1005];

int main(){
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	int s,n;
	scanf("%d%d",&s,&n);
	dp[1]=1;
	for(int i = 2 ; i <= s ; ++ i){
		for(int j = max(1,i - n) ; j < i ; ++ j){
			dp[i] += dp[j];
			dp[i] %= mod;
		}
	}
	printf("%d\n",dp[s]);
	return 0;
}
