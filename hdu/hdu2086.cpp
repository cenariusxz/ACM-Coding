#include<stdio.h>

int main(){
    long long n;
    double ans,a0,ax,c;
    while(scanf("%I64d",&n)!=EOF){
        scanf("%lf%lf",&a0,&ax);
        ans=n*a0+ax;
        for(long long i=1;i<=n;i++) {
            scanf("%lf",&c);
            ans-=2*(n+1-i)*c;
        }
        printf("%.2lf\n",ans/(n+1));
    }
    return 0;
}
