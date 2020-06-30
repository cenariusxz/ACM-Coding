#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, mod = 1e9 + 7;
ll dp[505][505][505];

// 从dx+1取到结尾的种类数，sum1=sum(d[x]+d[x+1]+...)，sum2=sum(x*d[x]+(x+1)*d[x+1]+...) 
ll dfs(int x, int sum1, int sum2){
	//printf("x:%d sum1:%d sum2:%d\n", x, sum1, sum2);
	x ++;
	if(dp[x][sum1][sum2] != -1)return dp[x][sum1][sum2];
	if(x + 1 == n - x + 1){	// dx取0 
		if(sum1 == 0 && sum2 == 0)return dp[x][sum1][sum2]=1;
		else return dp[x][sum1][sum2]=0;
	}
	if(x + 1 == n - x){	// dx取sum1 
		if(x*sum1 == sum2)return dp[x][sum1][sum2]=1;
		else return dp[x][sum1][sum2]=0;
	}
	ll sum = 0;
	for(int i = 0 ; i <= sum1 && x*i <= sum2 ; ++ i){
		sum += (i+1) * dfs(x, sum1-i, sum2-x*i);
	}
	//printf("x:%d sum1:%d sum2:%d sum:%lld\n", x,sum1,sum2,sum);
	return dp[x][sum1][sum2]=sum;
}

ll solve(){
	if(n == 1)return 1;
	ll ans = 0;
	for(int a1 = 1 ; a1 <= n ; ++ a1){
		for(int sum1 = 0 ; sum1 < a1 && sum1 + a1 <= n ; ++ sum1){
			for(int sum2 = sum1 ; sum2 < a1 && sum2 < n - sum1 ; ++ sum2){
				if(sum2 < a1){
					//if(a1 == 3 && sum1 == 1 && sum2 == 2)printf("aaaaa\n");
					ans += (n - a1 - sum1 + 1) * dfs(0, sum1, sum2);
					//printf("%d %d %d %lld\n", a1, sum1, sum2, ans);
					//if(a1 == 3 && sum1 == 1 && sum2 == 2)printf("aaaaa\n");
				}
			}
		}
	}
	return ans;
}

int main(){
	//scanf("%d", &n);
	//for(n = 1 ; n <= 100 ; ++ n){
		memset(dp, -1, sizeof(dp));
		n = 500;
		printf("%lld\n", solve());
	//}
	return 0;
}

