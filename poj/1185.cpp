#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1<<11;
const int maxm = 1<<21;

int n,m;
int line[65], num[65], cnt = 0;
int M[105];
int dp[105][65][65];
char s[15];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s",s);
		for(int j = 0 ; s[j] ; ++ j){
			if(s[j] == 'P')M[i] <<= 1;
			else M[i] = M[i]<<1|1;
		}
	}
	for(int i = 0 ; i < (1 << m) ; ++ i){
		if(i & ( (i<<1) | (i<<2) ))continue;
		line[++cnt] = i;
		int tmp = i;
		while(tmp){
			if(tmp & 1)num[cnt]++;
			tmp >>= 1;	
		}
		// for(int j = 9 ; j >= 0 ; -- j)printf("%1d",(i & (1<<j))?1:0);
		// printf("\n");
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int p = 1 ; p <= cnt ; ++ p){
			if(M[i] & line[p])continue;
			for(int j = 1 ; j <= cnt ; ++ j){
				if(line[p] & line[j])continue;
				for(int k = 1 ; k <= cnt ; ++ k){
					if((line[p] & line[k]) || (line[j] & line[k]))continue;
					dp[i][k][p] = max(dp[i][k][p], dp[i-1][j][k] + num[p]);
					ans = max(ans, dp[i][k][p]);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

