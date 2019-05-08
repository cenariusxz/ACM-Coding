#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b

int n[13],dp[13][2];

int main(){
    int N;
    while(scanf("%d",&N)!=EOF&&N!=0){
        memset(dp,0,sizeof(dp));
        int h,s,f;
        scanf("%d%d%d",&h,&s,&f);
        int i,j;
        for(i=1;i<=N;i++){
            scanf("%d",&n[i]);
            if(i==1){
                dp[1][0]=h*n[i]+s*n[i];
                dp[1][1]=n[i];
            }
            else if(n[i]==dp[i-1][1]){
                dp[i][0]=dp[i-1][0]+dp[i-1][1]*s;
                dp[i][1]=dp[i-1][1];
            }
            else if(n[i]<dp[i-1][1]){
                if(s<=f){
                    dp[i][0]=dp[i-1][0]+dp[i-1][1]*s;
                    dp[i][1]=dp[i-1][1];
                }
                else{
                    dp[i][0]=dp[i-1][0]+(dp[i-1][1]-n[i])*f+n[i]*s;
                    dp[i][1]=n[i];
                }
            }
            else if(n[i]>dp[i-1][1]){
                dp[i][0]=dp[i-1][0]+(n[i]-dp[i-1][1])*h+n[i]*s;
                dp[i][1]=n[i];
                for(j=1;j<i-1;j++){
                    if(dp[j][1]>dp[i-1]){
                        int dp0,dp1;
                        if(dp[j][1]<n[i]){
                            dp0=dp[j][0]+(i-j)*dp[j][1]*s+(n[i]-dp[j][1])*(h+s);
                            dp[i][0]=min(dp[i][0],dp0);
                        }
                        else if(dp[j][1]==n[i]){
                            dp0=dp[j][0]+(i-j)*dp[j][1]*s;
                            dp[i][0]=min(dp[i][0],dp0);
                        }
                        else if(dp[j][1]>n[i]){

                        }
                    }
                }
            }
        }
        printf("%d\n",dp[N]);
    }
    return 0;
}
