#include<stdio.h>
void Csort(int r[],int n){
    int i,j,t;
    for(i=1;i<n;i++){
        t=r[i];
        j=i-1;
        while(j>-1&&t<r[j]){
            r[j+1]=r[j];
            j--;
        }
        r[j+1]=t;
    }
}

int main(){
    int r[10]={9,8,7,6,5,4,3,2,0,1};
    Csort(r,10);
    for(int i=0;i<10;i++)printf("%d\t",r[i]);
    printf("\n");
}
