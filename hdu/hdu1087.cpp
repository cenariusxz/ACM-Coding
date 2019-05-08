#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b

int a[1002];
long long dp[1002];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        int q,i,j;
        long long m=0;
        for(q=1;q<=n;q++){
            scanf("%d",&a[q]);
            dp[q]=a[q];
            for(i=1;i<q;i++){
                if(a[i]<a[q]){
                    dp[q]=max(dp[q],dp[i]+a[q]);
                }
            }
            m=max(m,dp[q]);
        }
        printf("%I64d\n",m);
    }
    return 0;
}
