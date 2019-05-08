#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n;
long long a[100],b[100],two[240];

void fuck()
{
    long long A=0,B=0,C=0;
    int i;
    scanf("%lld",&n);
    n++;
    for(i=61;i>=0;i--){
        if((1ll<<i)&n){
            B=(((B+b[i])%mod+(n-C)%mod*C%mod)%mod+C%mod*a[i]%mod)%mod+A*two[i]%mod;
            B%=mod;
            A=A+a[i];
            A%=mod;
            C+=two[i];
    //        C%=mod;
            //printf(" %d %lld %lld %lld\n",i,A,B,C);
        }
    }
    printf("%lld\n",B);
}

void init()
{
    int i;
    a[0]=b[0]=0;
    two[0]=1;
    for(i=1;i<=130;i++)
        two[i]=two[i-1]*2LL%mod;
    for(i=1;i<=65;i++){
        a[i]=(2*a[i-1]%mod+two[i-1])%mod;
        b[i]=((2*b[i-1]%mod+two[i]*a[i-1]%mod)%mod+two[2*i-2])%mod;
        //printf("  %d %lld %lld\n",i,a[i],b[i]);
    }
}

int main()
{
    init();
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        printf("Case #%d: ",i);
        fuck();
    } 
 return 0;
}
