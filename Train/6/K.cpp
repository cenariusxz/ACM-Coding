#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int T,N,M,L;
int dp[10010];
int C[110],V[110],pos[110];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&M,&L);
		for(int i = 1; i <= N; ++i){
			scanf("%d",&pos[i]);
		}
		sort(pos + 1,pos + N + 1);
		int sum = 0;
		for(int i = 1; i <= M; ++i){
			scanf("%d%d",&C[i],&V[i]);
			sum += C[i];
		}
		sum = min(sum,L);
		memset(dp,0,sizeof(dp));
		int tmax = 0;
		for(int i = 1; i <= M; ++i){
			for(int j = sum; j >= C[i]; --j){
				dp[j] = max(dp[j],dp[j - C[i]] + V[i]);
				tmax = max(tmax,dp[j]);
			}
		}
		int pre = 1;
		int ans = 0;
		for(int i = 2; i <= N; ++i){
			if(pos[i] - pos[pre] > tmax){
				ans++;
				pre = i - 1;
				if(pos[i] - pos[pre] > tmax){
					ans = -2;
					break;
				}
			}
		}
		printf("%d\n",ans + 1);
	}
	return 0;
}
