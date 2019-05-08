#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b
int p[502],w[502],dp[10010];

int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        for(int q=1;q<=T;q++){
            memset(dp,-1,sizeof(dp));
            int E,F,N;
            dp[0]=0;
            scanf("%d%d%d",&E,&F,&N);
            int i,j,k,w0=F-E;
            for(i=1;i<=N;i++){
                scanf("%d%d",&p[i],&w[i]);
                for(j=w[i];j<=w0;j++){
                    if(dp[j-w[i]]>=0){
                        if(dp[j]>=0){
                            dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
                        }
                        else dp[j]=dp[j-w[i]]+p[i];
                    }
                }
            }
            if(dp[w0]==-1)printf("This is impossible.\n");
            else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w0]);
        }
    }
    return 0;
}
