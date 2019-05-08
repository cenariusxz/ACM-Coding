#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

char s1[1010],s2[1010];
int dp[2][1010],num[4];
int len,dif[2];

int main(){
	while(scanf("%s%s",s1 + 1,s2 + 1) != EOF){
		len = strlen(s1 + 1);
		if(len == 1){
			int d = abs(s2[1] - s1[1]);
			d = min(d,10 - d);
			printf("%d\n",d);
			continue;
		}
		s1[len + 1] = s1[len + 2] = s1[len + 3] = '0';
		s2[len + 1] = s2[len + 2] = s2[len + 3] = '0';
		memset(dp,-1,sizeof(dp));
		for(int i = 1; i <= 3; ++i){
			dif[0] = s2[1] - s1[1];
			dif[1] = (dif[0] > 0) ? dif[0] - 10 : 10 + dif[0];
			for(int f = 0; f < 2; ++f){
				int v = 0;
				for(int j = 2; j <= 3; ++j){
					int tmp;
					if(j <= i) tmp = ((s1[j] - '0' + dif[f]) % 10 + 10) % 10;
					else tmp = s1[j] - '0';
					v = v * 10 + tmp;
				}
				v = v * 10 + (s1[4] - '0'); 
				if(dp[0][v] == -1) dp[0][v] = abs(dif[f]);
				else dp[0][v] = min(dp[0][v],abs(dif[f]));
			}
		}
		int ans = 1 << 30;
		for(int o = 2; o <= len; ++o){
			int id = o & 1,nxt = id ^ 1;
			memset(dp[nxt],-1,sizeof(dp[nxt]));
			for(int s = 0; s < 1000; ++s){
				if(dp[id][s] == -1) continue;
				num[1] = s / 100;
				num[2] = s % 100 / 10;
				num[3] = s % 10;
				dif[0] = s2[o] - '0' - num[1];
				dif[1] = (dif[0] > 0) ? dif[0] - 10 : 10 + dif[0];
				for(int f = 0; f < 2; ++f){
					for(int i = 1; i <= 3; ++i){
						int v = 0;
						for(int j = 2; j <= 3; ++j){
							int tmp;
							if(j <= i) tmp = ((num[j] + dif[f]) % 10 + 10) % 10;
							else tmp = num[j];
							v = v * 10 + tmp;
						}
						v = v * 10 + (s1[o + 3] - '0');
						if(dp[nxt][v] == -1) dp[nxt][v] = dp[id][s] + abs(dif[f]);
						else dp[nxt][v] = min(dp[nxt][v],dp[id][s] + abs(dif[f]));
					}
				}
			}
			if(o == len){
				for(int s = 0; s < 1000; ++s) if(dp[nxt][s] != -1){
					ans = min(ans,dp[nxt][s]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
