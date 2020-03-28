#include<bits/stdc++.h>
using namespace std;
int n, dp[105];

int main(){
	scanf("%d",&n);
	int ans=-1, sum=0;
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d", &a);
		sum += a;
		if(a)a = -1;
		else a = 1;
		if(dp[i-1] > 0)dp[i] = dp[i-1] + a;
		else dp[i] = a;
		ans = max(ans, dp[i]);
	}
	printf("%d\n",ans + sum);
	return 0;
}
