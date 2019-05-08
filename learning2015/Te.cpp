#include<stdio.h>
#include<string.h>
long long dp[8][10];

void fun(){
    memset(dp,0,sizeof(dp));
    int i,j,k;
    dp[0][0]=1;
    for(i=1;i<=7;i++){
        for(j=0;j<=9;j++){
            for(k=0;k<=9;k++){
                if(j!=4&&(j!=6||k!=2)){
                    dp[i][j]=dp[i][j]+dp[i-1][k];
                }
            }
        }
    }
}

void fun2(){
    int i,j;
    for (i=0;i<=7;i++){
        for(j=0;j<=9;j++) printf("%I64d\t",dp[i][j]);
        printf("\n");
    }
}

int main(){
    long long n,m;
    fun();
    fun2();
    while(scanf("%I64d%I64d",&n,&m)!=EOF&&(n!=0||m!=0)){
        int i,j,x[2][8];
        long long ans=0;
        long long l=0,r=0;
        n--;
        x[0][7]=(n/1000000)%10;
        x[1][7]=(m/1000000)%10;
        x[0][6]=(n/100000)%10;
        x[1][6]=(m/100000)%10;
        x[0][5]=(n/10000)%10;
        x[1][5]=(m/10000)%10;
        x[0][4]=(n/1000)%10;
        x[1][4]=(m/1000)%10;
        x[0][3]=(n/100)%10;
        x[1][3]=(m/100)%10;
        x[0][2]=(n/10)%10;
        x[1][2]=(m/10)%10;
        x[0][1]=(n/1)%10;
        x[1][1]=(m/1)%10;
        for(i=7;i>0;i--){
            for(j=0;j<x[0][i];j++) l+=dp[i][j];
            for(j=0;j<x[1][i];j++) r+=dp[i][j];
        }
        l+=dp[1][x[0][1]];
        r+=dp[1][x[1][1]];
        ans=r-l;
        printf("%I64d\n",ans);
    }
    return 0;
}
