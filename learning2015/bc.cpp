#include<stdio.h>
#include<algorithm>
#define mod 10000007
using namespace std;
long long A[100002];

struct Mat{
    int mat[10][10];
}E;



Mat MatMultiply(Mat a,Mat b){
    int i,j,k;
    Mat temp;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            temp.mat[i][j]=0;
            for(k=0;k<2;k++){
                temp.mat[i][j]+=(a.mat[i][k]*b.mat[k][j]);
            }
            temp.mat[i][j]%=mod;
        }
    }
    return temp;
}

int MatQuickPower(Mat a,long long n){
    int i;
    for (i=0;i<2;i++) E.mat[i][i]=1;
    Mat temp=E,mat0=a;
    while(n>=0){
        if(n&1) temp=MatMultiply(temp,mat0);
        n>>=1;
        mat0=MatMultiply(mat0,mat0);
    }
    return temp.mat[0][0];
}


int main(){
    long long n,k;
    Mat T;
    T.mat[1][1]=T.mat[0][1]=T.mat[0][0]=1;
    T.mat[1][0]=0;
    while(scanf("%I64d%I64d",&n,&k)!=EOF){
        long long i,j,sum=0,ans,max1=0,max2=0;
        for(i=0;i<=k-2;i++) sum+=MatQuickPower(T,i);
        for(j=1;j<=n;j++){
            scanf("%I64d",&A[i]);
            ans=(ans+A[i])%mod;
            if(A[i]>max1){max1=A[i];}
            else if (A[i]>max2&&A[2]<max1) max2=A[i];
        }
        ans+=((max2*sum)%mod);
        ans-=max1;
        ans+=((sum+MatQuickPower(T,k-1)*max1)%mod);
        printf("%I64d\n",ans);
    }
    return 0;
}
