#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=1e9+7;

ll QP(ll a,ll n){
	ll tmp=a,ans=1;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

