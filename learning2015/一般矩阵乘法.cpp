#include<stdio.h>
struct Mat{
    int mat[10][10];
    int row;
    int col;
};

Mat MatMultiply(Mat a,Mat b){
    Mat temp;
    int i,j,k;
    for(i=0;i<a.row;i++){
        for(j=0;j<b.col;j++){
            temp.mat[i][j]=0;
            for(k=0;k<a.col;k++){
                temp.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
            }
            temp.mat[i][j]%mod;
        }
    }
    return temp;
}
