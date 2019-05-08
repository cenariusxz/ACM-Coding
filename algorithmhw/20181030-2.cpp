#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;

int a[maxn],sum[maxn];
int dp[maxn];
int n,B;

int main(){
	scanf("%d%d",&n,&B);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0] = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int sum = 0, Max = -INF;
		for(int j = i-1 ; j >= 0 ; -- j){
			sum += a[j+1];
			Max = max(Max,a[j+1]);
			if(sum > B)break;
			dp[i] = min(dp[i], dp[j] + Max);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
