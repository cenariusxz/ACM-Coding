#include<stdio.h>
long long a[35][2];
void fun(){
    a[0][0]=1;
    a[0][1]=0;
    for(int i=1;i<=33;i++){
        a[i][0]=3*a[i-1][0]+2*a[i-1][1];
        a[i][1]=a[i-1][0]+a[i-1][1];
    }
    return;
}


int main(){
    fun();
    int N;
    while(scanf("%d",&N)!=EOF&&N!=-1){
        printf("%I64d, %I64d\n",a[N][0],a[N][1]);
    }
    return 0;
}
