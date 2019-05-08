#include<bits/stdc++.h>
using namespace std;
double dp[2][1255][1255];
int c[1255],w[1255];
int n,m;

void fuck()
{
	int i,j;
	double ans=15000;
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	dp[1][0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i-1>=j)
				dp[1][i][j]=max(dp[1][i-1][j]*(100-w[i])/100.0+(1-dp[1][i-1][j])*w[i]/100.0,
								(1-dp[0][i-1][j])*(100-w[i])/100.0+dp[0][i-1][j]*w[i]/100.0);
			if(j) dp[1][i][j]=max(dp[0][i-1][j-1]*(100-c[i])/100.0+(1-dp[0][i-1][j-1])*c[i]/100.0,dp[1][i][j]);
			if(j) dp[1][i][j]=max((1-dp[1][i-1][j-1])*(100-c[i])/100.0+dp[1][i-1][j-1]*c[i]/100.0,dp[1][i][j]);
			if(i-1>=j)
				dp[0][i][j]=max(dp[0][i-1][j]*(100-w[i])/100.0+(1-dp[0][i-1][j])*w[i]/100.0,
								(1-dp[1][i-1][j])*(100-w[i])/100.0+dp[1][i-1][j]*w[i]/100.0);
			if(j) dp[0][i][j]=max(dp[1][i-1][j-1]*(100-c[i])/100.0+(1-dp[1][i-1][j-1])*c[i]/100.0,dp[0][i][j]);
			if(j) dp[0][i][j]=max((1-dp[0][i-1][j-1])*(100-c[i])/100.0+dp[0][i-1][j-1]*c[i]/100.0,dp[0][i][j]);
			//printf(" dp[0][%d][%d]=%.3lf\n",i,j,dp[0][i][j]);
			//printf(" dp[1][%d][%d]=%.3lf\n",i,j,dp[1][i][j]);
		}
	}
	for(i=0;i<=m;i++){
		ans=min(ans,15000*(1-2*dp[0][n][i]));
	}
	printf("%.3f\n",ans);
}

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}
