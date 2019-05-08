#include<stdio.h>

int QuickPow(int a,long long n,int p){
    int temp=a,ans=1;
    while(n){
        if(n&1)ans=ans*temp%p;
        n>>=1;
        temp=temp*temp%p;
    }
    return ans;
}

int main(){
    int T;
    while(scanf("%d",&T)!=EOF&&T!=0){
        for(int q=1;q<=T;q++){
            long long N;
            int ans;
            scanf("%I64d",&N);
            if(0==N) ans=0;
            else ans=(QuickPow(4,N-1,100)+QuickPow(2,N-1,100))%100;
            printf("Case %d: %d\n",q,ans);
            if(q==T)printf("\n");
        }
    }
    return 0;
}
