#include<stdio.h>
#define max(a,b) (a)>(b)?a:b
int A[110][110];

int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        int i,j;
        for(i=1;i<=N;i++){
            for(j=1;j<=i;j++){
                scanf("%d",&A[i][j]);
            }
        }
        for(i=1;i<=N;i++){
            for(j=1;j<=i;j++){
                if(i>1){
                    if(j==1){
                        A[i][j]+=A[i-1][j];
                    }
                    else if(j==i){
                        A[i][j]+=A[i-1][j-1];
                    }
                    else{
                        A[i][j]+=max(A[i-1][j],A[i-1][j-1]);
                    }
                }
            }
        }
        int ans=A[1][1];
        for(i=1;i<=N;i++){
            if(A[N][i]>ans)ans=A[N][i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
