#include<cstdio>
using namespace std;
typedef long long ll;
#define MOD 1000000007ll
int T;
ll p,q,K;
ll QPow(ll a,ll p,ll mod){
    if(!p){
        return 1ll;
    }
    ll res=QPow(a,p>>1,mod);
    res=res*res%mod;
    if((p&1ll)==1ll){
        res=(a%mod*res)%mod;
    }
    return res;
}
int main(){
    scanf("%d",&T);
    for(;T;--T){
        scanf("%lld%lld%lld",&q,&p,&K);
        printf("%lld\n",(((QPow(p,K,MOD)+QPow(p-2ll*q,K,MOD))%MOD*QPow(2ll,MOD-2ll,MOD))%MOD
        *QPow(QPow(p,K,MOD),MOD-2ll,MOD))%MOD);
    }
    return 0;
}
