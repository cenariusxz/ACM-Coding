#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e8;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

int n, m;
int dp[15][maxn];
int M[15];
vector<int>V[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			int a;
			scanf("%d",&a);
			a ^= 1;
			M[i] = M[i]<<1|a;
		}
	}
	for(int i = 0 ; i < (1 << m) ; ++ i){
		if( i & (i<<1) )continue;
		for(int j = 0 ; j < (1 << m) ; ++ j){
			if( j & (j<<1))continue;
			if(i & j)continue;
			V[i].PB(j);
		}
	}
	dp[0][0] = 1;
	for(int t = 1 ; t <= n ; ++ t){
		for(int i = 0 ; i < (1 << m) ; ++ i){
			if(i & M[t])continue;
			for(int k = 0 ; k < V[i].size() ; ++ k){
				int j = V[i][k];
				dp[t][i] += dp[t-1][j];
				if(dp[t][i] >= mod)dp[t][i] -= mod;	
			}
		}
	}
	int ans = 0;
	for(int i = 0 ; i < (1 << m) ; ++ i){
		ans += dp[n][i];
		if(ans >= mod)ans -= mod;	
	}
	printf("%d\n", ans);
	return 0;
}

