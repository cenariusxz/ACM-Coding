#include<stdio.h>
long long a[25],b[25],c[25],k[25];

void fun(){
    int i;
    k[1]=2;
    for(i=2;i<=20;i++)k[i]=3*k[i-1]+2;
    a[1]=1;
    for(i=2;i<=20;i++)a[i]=k[i-1]+a[i-1]+1;
    b[1]=1;
    for(i=2;i<=20;i++)b[i]=b[i-1]+1+k[i-1];
    c[1]=2;
    for(i=2;i<=20;i++)c[i]=a[i-1]+2+b[i-1];
}


int main(){
    fun();
    int T;
    while(scanf("%d",&T)!=EOF){
        for(int q=1;q<=T;q++){
            int n;
            scanf("%d",&n);
            printf("%I64d\n",c[n]);
        }
    }
    return 0;
}
