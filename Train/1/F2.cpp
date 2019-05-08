#include <stdio.h>
#include <math.h>
#include <string.h>

typedef pair<int,int> pii;

const int mod = 1e4 + 7;
int dp[110][110][1010];
int C[110][110];
int id[1010];
pii P[110];

void Magic(int &x,int y){
	x += y;
	if(x >= mod) x -= mod;
}

int main(){
	for(int i = 1; i <= 100; ++i){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j){
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	int T,n,W;
	int num[1010];
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d",&n,&W);
		int cnt = 0;
		memset(id,0,sizeof(id));
		for(int i = 1; i <= n; ++i){
			int a;
			scanf("%d",&a);
			if(id[a] == 0) ++cnt,P[cnt].first = a;
			P[id[a]].second++;
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= W; ++j){
				for(int o = 1; o <= cnt; ++o){
					int top = min(P[o].second,i);
					for(int k = 1; k <= top; ++k){
						if(j >= k * P[o].first){
							Magic(dp[i][j],C[i][k] * 
									dp[i - k][j - k * P[o].first]);
						}
					}
				}
			}
		}
		
	}
	return 0;
}
