#include<stdio.h>
#define ll long long
const ll mod=1000000007;

int main(){
	ll n,tsum = 0;
	while(scanf("%lld",&n)!=EOF){
		ll b1,a1;
		b1=n/2+1;
		a1=(n-5)/2+1;
		ll t1=n/5,t2=n/5-1;
		if(t2%2){
			ll t=t1;
			t1=t2;
			t2=t;
		}
		t1=(t1+1)/2;
		t2=(t2+2)/2;
		ll x1,x2;
		x1=2*a1+(t1-1)*(-5); x2=t1;
		if (x1%2) x2/=2; 
		else x1/=2;
		ll s1=(x1%mod)*(x2%mod)%mod;
		x1=2*b1+(t2-1)*(-5); x2=t2;
		if (x1%2) x2/=2; 
		else x1/=2;
		ll s2=(x1%mod)*(x2%mod)%mod;
		ll s=s1+s2;
		printf("%lld\n",s%mod);
	//	tsum += s;
	}
	//	printf("%lld\n",tsum + 1);
	return 0;
}
