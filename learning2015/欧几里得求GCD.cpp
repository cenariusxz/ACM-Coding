#include<stdio.h>
int GCD(int a,int b){
    if(a<b){
        int t;
        t=a;
        a=b;
        b=t;
    }
    if(b==0)return a;
    else return GCD(b,a%b);
}

int main(){
    int a,b,m;
    scanf("%d%d",&a,&b);
    m=GCD(a,b);
    printf("%d\n",m);
    return 0;
}
