#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int n, dp[1005];
int a[10] = {0,10,20,50,100};

int main(){
	scanf("%d",&n);
	dp[0] = 1;
	for(int i = 1 ; i <= 4 ; ++ i){
		for(int j = a[i] ; j <= n ; ++ j){
			dp[j] += dp[j - a[i]];
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}

