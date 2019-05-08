#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b

int dp[4005],l[5];

int main(){
	int n,i,j,c=0,t;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(i=1;i<=3;i++){
		scanf("%d",&t);
		for(j=1;j<i;j++){
			if(l[j]==t)break;
		}
		if(j==i)l[++c]=t;
	}
	dp[0]=0;
	for(i=1;i<=c;i++){
		for(j=l[i];j<=n;j++){
			if(dp[j-l[i]]!=-1){
				dp[j]=max(dp[j],dp[j-l[i]]+1);
			}
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
