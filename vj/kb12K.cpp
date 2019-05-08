#include<stdio.h>
#include<string.h>

int p[206],d[206];
int dp[206][25][2];
int pre[206][25][2];

inline int abs(int a){return a>0?a:-a;}

void print(int i,int j){
	if(i==0&&j==0)return;
	print(pre[i][j][0],pre[i][j][1]);
	if(pre[i][j][1]<j)printf(" %d",i);
}

int main(){
	int n,m,c=0;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		for(int i=1;i<=n;++i)scanf("%d%d",&p[i],&d[i]);
		memset(dp,0x3f,sizeof(dp));
		memset(pre,0,sizeof(pre));
		dp[0][0][0]=dp[0][0][1]=0;
		for(int i=1;i<=n;++i){
				dp[i][j][0]=dp[i-1][j][0];
				dp[i][j][1]=dp[i-1][j][1];
				pre[i][j][0]=i-1;
				pre[i][j][1]=j;
				if(abs(dp[i-1][j-1][0]+p[i]-d[i])<abs(dp[i][j][0])){
					dp[i][j][0]=dp[i-1][j-1][0]+p[i]-d[i];
					dp[i][j][1]=dp[i-1][j-1][1]+p[i]+d[i];
					pre[i][j][0]=i-1;
					pre[i][j][1]=j-1;
				}
				else if(abs(dp[i-1][j-1][0]+p[i]-d[i])==abs(dp[i][j][0])&&dp[i-1][j-1][1]+p[i]+d[i]>dp[i][j][1]){
					dp[i][j][0]=dp[i-1][j-1][0]+p[i]-d[i];
					dp[i][j][1]=dp[i-1][j-1][1]+p[i]+d[i];
					pre[i][j][0]=i-1;
					pre[i][j][1]=j-1;
				}
			}
		}
		printf("Jury #%d\n",++c);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",(dp[n][m][0]+dp[n][m][1])/2,(dp[n][m][1]-dp[n][m][0])/2);
		print(n,m);
		printf("\n");
	}
	return 0;
}
