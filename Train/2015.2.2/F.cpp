#include<stdio.h>
#include<string.h>
#define max(a,b) (a)>(b)?a:b
#define min(a,b) (a)<(b)?a:b
long long P[510],W[510],dp[10100];

int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        memset(P,0,sizeof(P));
        memset(W,0,sizeof(W));
        int q;
        for(q=1;q<=T;q++){
            int E,F,N;
            scanf("%d%d%d",&E,&F,&N);
            int W0=F-E;
            int s;
            for(s=1;s<=N;s++){
                scanf("%I64d%I64d",&P[s],&W[s]);
            }
            long long i,j;
            for(i=1;i<=W0;i++)dp[i]=0x7FFFFFFF;
            for(i=1;i<=N;i++){
                for(j=W[i];j<=W0;j++){
                    dp[j]=min(dp[j-W[i]]+P[i],dp[j]);
                }
            }
            if(dp[W0]==0x7FFFFFFF)printf("This is impossible.\n");
            else printf("The minimum amount of money in the piggy-bank is %I64d.\n",dp[W0]);
        }
    }
    return 0;
}
