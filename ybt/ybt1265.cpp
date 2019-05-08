#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

char s[maxn],t[maxn];
int dp[maxn][maxn];

int main(){
	scanf("%s%s",s+1,t+1);
	int n = strlen(s+1);
	int m = strlen(t+1);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i] == t[j])dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}

