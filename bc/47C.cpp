#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
char a[1005],b[1005];
int dp[1005][1005];
ll dp2[2][1005][1005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",a+1,b+1);
		int n=strlen(a+1),m=strlen(b+1);
		int i,j;
		memset(dp,0,sizeof(dp));
		int cnt=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(dp[i][j]>cnt)cnt=dp[i][j];
			}
		}
		int ans=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(b[i]==a[j]){
					dp[i][j]=dp[i-1][j-1]+1;
					if(dp[i][j]==cnt)ans++;
				}
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d %d\n",cnt,cnt==0?1:ans);
		
	}
	return 0;
}
