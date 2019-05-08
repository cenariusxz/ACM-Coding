#include<stdio.h>
#define ll long long

ll QuickPow(ll a,ll n,ll mod){
	ll tmp=a,ans=1;
	while(n){
		if(n&1)	ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

int main(){
	ll a,n,mod;
	while(scanf("%lld%lld%lld",&a,&n,&mod)!=EOF){
		ll m=QuickPow(a,n,mod);
		printf("%lld\n",m);
	}
	return 0;
}
