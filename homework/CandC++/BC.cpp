#include<stdio.h>
#include<algorithm>
#define mod 10000007
using namespace std;
long long A[100003];

struct Mat{
    long long mat[10][10];
}E;

Mat MatMultiply(Mat a,Mat b){
    long long i,j,k;
    Mat temp;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            temp.mat[i][j]=0;
            for(k=0;k<3;k++){
                temp.mat[i][j]+=(a.mat[i][k]*b.mat[k][j]);
            }
            temp.mat[i][j]%=mod;
        }
    }
    return temp;
}

Mat MatQuickPower(Mat a,long long n){
    long long i;
    for (i=0;i<3;i++) E.mat[i][i]=1;
    Mat temp=E,mat0=a;
    while(n>0){
        if(n&1) temp=MatMultiply(temp,mat0);
        n>>=1;
        mat0=MatMultiply(mat0,mat0);
    }
    return temp;
}


int main(){
    long long n,k;
    Mat T;
    T.mat[2][1]=T.mat[1][2]=T.mat[0][2]=T.mat[1][1]=T.mat[0][1]=T.mat[0][0]=1;
    T.mat[2][2]=T.mat[2][0]=T.mat[1][0]=0;
    while(scanf("%I64d%I64d",&n,&k)!=EOF){
        long long i,j,sum1=0,sum2=0,ans=0,max1=0,max3=0;
        for(j=1;j<=n;j++){
            scanf("%I64d",&A[j]);
            ans=(ans+A[j])%mod;
            if(A[j]>max1){max3=max1;max1=A[j];}
            else if (A[j]>max3&&A[j]<max1) max3=A[j];
        }
        if(n==1)ans=((ans+(max1+max3)%mod)%mod);
        else {
            Mat t=MatQuickPower(T,k-2);
            sum1=(t.mat[0][0]*2%mod+t.mat[0][1]+t.mat[0][2])%mod;
            ans=((ans+((max3*sum1)%mod))%mod);
            t=MatQuickPower(T,k-1);
            sum2=(t.mat[0][0]*2%mod+t.mat[0][1]+t.mat[0][2]-1)%mod;
            ans=((ans+((sum2*max1)%mod))%mod);
            
        }
		printf("%I64d\n",ans);
    }
    return 0;
}
