#include<stdio.h>
struct Mat{
    int mat[10][10];
    int row;
    int col;
}E;

int QuickPow(int a,int n,int p){
    int temp=a,ans=1;
    while(n){
        if(n&1)ans=ans*temp%p;
        n>>=1;
        temp=temp*temp%p;
    }
    return ans;
}

Mat MatMultiply(Mat a,Mat b){
    int i,j,k;
    Mat temp;
    for(i=0;i<a.row;i++){
        for(j=0;j<b.col;j++){
            temp.mat[i][j]=0;
            for(k=0;k<a.row;k++){
                temp.mat[i][j]+=(a.mat[i][k]*b.mat[k][j]);
            }
            temp.mat[i][j]%=mod;
        }
    }
    return temp;
}

Mat MatQuickPower(Mat a,long long n){
    int i;
    for (i=0;i<a.row;i++) E.mat[i][i]=1;
    Mat temp=E,mat0=a;
    while(n>=0){
        if(n&1) temp.mat=MatMultiply(temp,mat0);
        n>>=1;
        mat0=MatMultiply(mat0,mat0);
    }
    return temp;
}
