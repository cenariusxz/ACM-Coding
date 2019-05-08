#include<stdio.h>
#include<string.h>
int m[11][101];
long long dp[11][101];
int r[11][101];
int row,col;
void pr(int i,int j){
    printf("%d",i);
    if(j!=col) {
        printf(" ");
        int z=r[i][j];
        pr(z,j+1);
    }
    else printf("\n");
}

long long min(int i,int i1,int i2,int i3,int j){
    long long d1=dp[i1][j],d2=dp[i2][j],d3=dp[i3][j];
    if(d1<=d2&&d1<=d3){
        r[i][j-1]=i1;
        return d1;

    }
    if(d2<d1&&d2<=d3){
        r[i][j-1]=i2;
        return d2;

    }
    if(d3<d1&&d3<d2){
        r[i][j-1]=i3;
        return d3;

    }
}

int main(){

    while(scanf("%d%d",&row,&col)!=EOF){
        int i,j,t;
        long long ans=0xFFFFFFF;
        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){
                scanf("%d",&m[i][j]);
                if(j==col){dp[i][j]=m[i][j];r[i][j]=i;}
                else dp[i][j]=0xFFFFFFF;

            }
        }
        for(j=col-1;j>=1;j--){
            for(i=1;i<=row;i++){
                if(i==1) {
                    dp[i][j]=min(1,1,2,row,j+1)+m[i][j];
                }
                else if(i==row){
                    dp[i][j]=min(row,1,row-1,row,j+1)+m[i][j];
                }
                else{
                    dp[i][j]=min(i,i-1,i,i+1,j+1)+m[i][j];
                }
            }
        }
        for(i=1;i<=row;i++){
            if(dp[i][1]<ans){
                ans=dp[i][1];
                t=i;
            }
        }
        pr(t,1);
        printf("%d\n",ans);
    }
    return 0;
}
