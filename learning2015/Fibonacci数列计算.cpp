#include<stdio.h>
long long F(int n){
    if (n==0||n==1) return n;
    else return (F(n-1)+F(n-2));
}

int main(){
    int n;
    scanf("%d",&n);
    long long f;
    f=F(n);
    printf("%I64d\n",f);
    return 0;
}
