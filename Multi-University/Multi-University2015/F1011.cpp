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

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int a=n/2;
		int b=(n+1)/2;
		ll ans=QP(2,a+b-1)-1;
		printf("%lld\n",ans);
	}
	return 0;
}
