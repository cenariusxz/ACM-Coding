#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s1[1005],s2[1005];
int dp[1005][1005];

int main(){
	while(scanf("%s%s",s1+1,s2+1)!=EOF){
		int n=strlen(s1+1);
		int m=strlen(s2+1);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(s1[i]==s2[j]){
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
