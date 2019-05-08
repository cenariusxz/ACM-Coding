#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

double dp[maxn];
double sum[maxn];

int n,w,k;

int main(){
	scanf("%d%d%d",&n,&k,&w);
	if(k-1 + w < n){
		printf("0.00000\n");
		return 0;
	}
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	for(int i = k ; i <= n ; ++ i)dp[i] = 1.0;
	for(int i = k+1+w ; i >= k ; -- i)sum[i] = sum[i+1] + dp[i];
	for(int i = k-1 ; i >= 0 ; -- i){
		dp[i] = (sum[i+1] - sum[i+w+1]) / (1.0*w);
		sum[i] = sum[i+1] + dp[i];
	}
	printf("%.5lf\n",dp[0]);
	return 0;
}
