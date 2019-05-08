#include<stdio.h>
#include<string.h>
#define max(a,b) (a)>(b)?a:b
char x[1000],y[1000];
int dp[1000][1000];
int main(){
    while(scanf("%s%s",x,y)!=EOF){
        getchar();
        int i,j,l1,l2;
        l1=strlen(x);
        l2=strlen(y);
        memset(dp,0,sizeof(dp));
        for(i=0;i<l1;i++){
            for(j=0;j<l2;j++){
                if(x[i]==y[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        int ans=dp[l1][l2];
        printf("%d\n",ans);
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
    }
    return 0;
}
