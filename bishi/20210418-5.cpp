#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-12;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

double dp[2][4005][2005];

void solve(int n){
	memset(dp,0,sizeof(dp));
	dp[0][0][0] = 1;
	double ans = 0.0;
	for(int t = 1 ; t <= n ; ++ t){
		int pre = ((t-1)&1), now = (t&1);
		memset(dp[now], 0, sizeof(dp[now]));
		for(int left = 0 ; left <= min(2*(t-1), n) ; ++ left){
			int right = 2*(t-1) - left;
			int limit = min(left, right);
			int sum = 2*n - 2*(t-1), suml = n - left, sumr = n - right;
			for(int pairs = 0 ; pairs <= limit ; ++ pairs){
				//if(dp[pre][left][pairs] < eps)continue;
				// left left
				if(suml >= 2){
					dp[now][left+2][pairs] += suml * 1.0 / sum * (suml - 1) / (sum - 1) * dp[pre][left][pairs];
				}
				// left right
				if(suml && sumr){
					dp[now][left+1][pairs+1] += suml * 2.0 / sum * sumr / (sum - 1) * dp[pre][left][pairs];
				}
				// right right
				if(sumr >= 2){
					dp[now][left][pairs] += sumr * 1.0 / sum * (sumr - 1) / (sum - 1) * dp[pre][left][pairs];
				}
			}
		}
	}
	for(int pairs = 1 ; pairs <= n ; ++ pairs)ans += pairs * dp[n&1][n][pairs];
	printf("%d : %.6lf\n", n, ans);
}

int main(){
	for(int i = 2000 ; i <= 2000 ; ++ i)solve(i);
	return 0;
}

