#include<stdio.h>
#include<string.h>

int dp[100005];
char s[100005];

int main(){
	scanf("%s",s+1);
	memset(dp,0,sizeof(dp));
	int l=strlen(s+1),i;
	for(i=1;i<l;i++){
		dp[i]=dp[i-1];
		if(s[i]==s[i+1]){
			dp[i]++;
		}
	}
	dp[l]=dp[l-1];
	int m;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",dp[b-1]-dp[a-1]);
	}
	return 0;
}
