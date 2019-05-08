#include<stdio.h>
#include<string.h>
#define max(a,b) (a)>(b)?a:b

int g[101][101],dp[101][101];

int main(){
    int C;
    while(scanf("%d",&C)!=EOF){
        for(int q=1;q<=C;q++){
            int N;
            scanf("%d",&N);
            memset(dp,0,sizeof(dp));
            int i,j;
            for(i=1;i<=N;i++){
                for(j=1;j<=i;j++){
                    scanf("%d",&g[i][j]);
                }
            }
            dp[1][1]=g[1][1];
            for(i=2;i<=N;i++){
                for(j=1;j<=i;j++){
                    if(j==1)dp[i][j]=dp[i-1][j]+g[i][j];
                    else if(j==i)dp[i][j]=dp[i-1][j-1]+g[i][j];
                    else dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+g[i][j];
                }
            }
            int m=dp[N][1];
            for(i=2;i<=N;i++)if(dp[N][i]>m)m=dp[N][i];
            printf("%d\n",m);
        }

    }
    return 0;
}
