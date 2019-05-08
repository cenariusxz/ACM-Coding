#include<stdio.h>
#include<string.h>

double dp[2005][2005];

int main(){
	int n,t;
	double p;
	scanf("%d%lf%d",&n,&p,&t);
	int i,j;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=1;i<=t;i++){
		for(j=0;j<=n;j++){
			if(j==0)dp[i][j]=dp[i-1][j]*(1-p);
			else if(j==n)dp[i][j]=dp[i-1][j-1]*p+dp[i-1][j];
			else dp[i][j]=dp[i-1][j-1]*p+dp[i-1][j]*(1-p);
		}
	}
	double ans=0;/*
	printf("%lf\n",dp[0][0]);
	for(i=0;i<=t;i++){
		for(j=0;j<=n;j++){
			printf("%lf ",dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	for(i=1;i<=n;i++){
		ans+=dp[t][i]*i;
	}
	printf("%.12lf\n",ans);
	return 0;
}
