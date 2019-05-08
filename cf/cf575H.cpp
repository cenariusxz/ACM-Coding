#include<stdio.h>
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
	int n;
	scanf("%d",&n);
	ll a=1;
	ll an,an1,a2n1;
	for(int i=1;i<=2*n+1;++i){
		a=a*i%mod;
		if(i==n)an=a;
		if(i==n+1)an1=a;
		if(i==2*n+1)a2n1=a;
	}
	printf("%I64d\n",((2*a2n1)%mod*(QP(an1,mod-2))%mod*(QP(an,mod-2))%mod-1+mod)%mod);
	return 0;
}
