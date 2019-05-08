#include<stdio.h>
#define max(a,b) (a)>(b)?a:b
int A[1010];
long long dp[1010];
int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        int i,j;
        for(i=1;i<=N;i++) scanf("%d",&A[i]);
        for(i=1;i<=N;i++){
            dp[i]=1;
            for(j=1;j<i;j++){
                if(A[i]>A[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int ans=1;
        for(i=1;i<=N;i++){
            if(dp[i]>ans)ans=dp[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
