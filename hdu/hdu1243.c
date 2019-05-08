#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b

int dp[2105][2105],v[30];

int main(){
	char s1[50],s2[2105],s3[2105];
	int n;
	while(scanf("%d",&n)!=EOF){
		scanf("%s",s1);
		int i,t,j,ans=0;
		for(i=0;i<n;i++){
			scanf("%d",&t);
			v[s1[i]-'a']=t;
		}
		memset(dp,0,sizeof(dp));
		scanf("%s%s",s2,s3);
		int l2=strlen(s2),l3=strlen(s3);
		for(i=1;i<=l2;i++){
			for(j=1;j<=l3;j++){
				if(s2[i-1]==s3[j-1]){
					dp[i][j]=dp[i-1][j-1]+v[s2[i-1]-'a'];
				}
				else {
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
				ans=max(ans,dp[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
