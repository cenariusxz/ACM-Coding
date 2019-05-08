#include<stdio.h>
#include<math.h>
#define ll long long

ll QuickPow(ll a,ll n){
    ll tmp=a,ans=1;
    while(n){
        if(n&1)ans=ans*tmp;
        tmp=tmp*tmp;
        n>>=1;
    }
    return ans;
}

int main(){
	ll p,q,n;
	while(scanf("%lld%lld%lld",&p,&q,&n)==3&&p+q+n){
		ll a=(p+(ll)(sqrt(p*p-4*q*1.0)))/2;
		ll b=(p-(ll)(sqrt(p*p-4*q*1.0)))/2;
	//	printf("%lld %lld\n",a,b);
		ll ans=QuickPow(a,n)+QuickPow(b,n);
		printf("%lld\n",ans);
	}
	return 0;
}
