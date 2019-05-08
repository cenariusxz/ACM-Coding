#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e3 + 5;

char s[maxn],t[maxn];
int dp[maxn][maxn];

int main(){
	while(scanf("%s%s",s+1,t+1)!=EOF){
		dp[0][0] = dp[0][1] = dp[1][0] = 0;
		for(int i = 1 ; s[i] ; ++ i){
			for(int j = 1 ; t[j] ; ++ j){
				if(s[i] == t[j])dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		int len1 = strlen(s+1), len2 = strlen(t+1);
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}
