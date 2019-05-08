#include<stdio.h>
#include<string.h>

double dp[105][105][105];

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	memset(dp,0,sizeof(dp));
	dp[a][b][c]=1;
	int i,j,k;
	for(i=a;i>=0;i--){
		for(j=b;j>=0;j--){
			for(k=c;k>=0;k--){
				if((i==0&&j==0&&k==0)||(i==a&&j==b&&k==c))continue;
			/*	else if(i==0&&j==0)dp[i][j][k]=dp[i][j][k+1];
				else if(j==0&&k==0)dp[i][j][k]=dp[i+1][j][k];
				else if(i==0&&k==0)dp[i][j][k]=dp[i][j+1][k];
			*/	else{
					dp[i][j][k]=0;
					dp[i][j][k]+=dp[i+1][j][k]*(i+1)*k/((i+j+k+1)*(i+j+k)*1.0);
					dp[i][j][k]+=dp[i][j+1][k]*(j+1)*i/((i+j+k+1)*(i+j+k)*1.0);
					dp[i][j][k]+=dp[i][j][k+1]*(k+1)*j/((i+j+k+1)*(i+j+k)*1.0);
					printf("%d %d %d %.10lf\n",i,j,k,dp[i][j][k]);
				}
			}
		}
	}

	printf("%.10lf %.10lf %.10lf\n",dp[1][0][0],dp[0][1][0],dp[0][0][1]);
	return 0;
}
