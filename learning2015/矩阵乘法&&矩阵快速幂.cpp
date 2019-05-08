#include<stdio.h>
#include<string.h>
struct Mat{
    int mat[11][11];
    int N;
}E;
int mod=9973;
Mat matMultiply(Mat a,Mat b){
    Mat temp;
    temp.N=a.N;
    int i,j,k;
    for(i=0;i<a.N;i++){
        for(j=0;j<a.N;j++){
            temp.mat[i][j]=0;
            for(k=0;k<a.N;k++){
                temp.mat[i][j]+=((a.mat[i][k]*b.mat[k][j]));
            }
            temp.mat[i][j]%=mod;
        }
    }
    return temp;
}
Mat QuickPowerMat(Mat a,long long n){
    int i;
    for(i=0;i<a.N;i++) E.mat[i][i]=1;
    Mat temp=E,mat0=a;
    temp.N=E.N=a.N;
    while(n>=1){
        if(n&1)temp=matMultiply(temp,mat0);
        n>>=1;
        mat0=matMultiply(mat0,mat0);
    }
    return temp;
}
