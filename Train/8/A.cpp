#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[110][110];
int A[110];

int main(){
	int T,N,M;
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d",&N,&M);
		for(int i = 1; i <= N; ++i){
			scanf("%d",&A[i]);
		}
		sort(A + 1,A + N + 1);
		for(int i = 0; i <= N; ++i){
			for(int j = 0; j <= M; ++j){
				dp[i][j] = 1LL << 60;
			}
		}
		dp[0][0] = 0;
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= M; ++j){
				for(int k = 0; k < i - 1; ++k){
					if(dp[k][j - 1] + A[i] - A[k + 1] < dp[i][j]){
						dp[i][j] = dp[k][j - 1] + A[i] - A[k + 1];
					}
				}
				if(dp[i - 1][j - 1] < dp[i][j]){
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		printf("Case #%d: %lld\n",tt,dp[N][M]);
	}
	return 0;
}
