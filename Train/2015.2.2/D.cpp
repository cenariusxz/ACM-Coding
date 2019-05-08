#include<stdio.h>
#include<string.h>
#define max(a,b) (a)>(b)?a:b

int W[3500],D[3500];
long long dp[15000];
int main(){
    int N,M;
    while(scanf("%d%d",&N,&M)!=EOF){
        int q;
        for(q=1;q<=N;q++)scanf("%d%d",&W[q],&D[q]);
        int i,j;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=N;i++){
            for(j=M;j>=W[i];j--){
                dp[j]=max(dp[j],dp[j-W[i]]+D[i]);
            }
        }
        long long ans=dp[0];
        for(i=1;i<=M;i++){
            if(dp[i]>ans) ans=dp[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
