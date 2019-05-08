#include<stdio.h>
#define mod 2009
int QuickPow(int a,long long n){
    int temp=a,ans=1;
    while(n){
        if(n&1)ans=temp*ans%mod;
        temp=temp*temp%mod;
        n>>=1;
    }
    return ans;
}

int main(){
    long long n;
    while(scanf("%I64d",&n)!=EOF){
        if(n==1)printf("1\n");
        else if(n==2)printf("2\n");
        else {
            int ans=1;
            long long p=n/3;
            if (n%3==1){
                ans=4*QuickPow(3,p-1)%mod;
            }
            else if(n%3==2){
                ans=2*QuickPow(3,p)%mod;
            }
            else if(n%3==0){
                ans=1*QuickPow(3,p)%mod;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
