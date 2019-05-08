#include<stdio.h>
typedef long long ll;

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

int main(){
	ll x,y,z;
	ll a,b,tmp;
	while(scanf("%lld%lld%lld%lld%lld",&x,&y,&z,&a,&b)!=EOF){
		ll ans1=(a-1)/x+(a-1)/y+(a-1)/z,ans2=b/x+b/y+b/z;
		tmp=x*y/gcd(x,y);
		ans1-=(a-1)/tmp;
		ans2-=b/tmp;
		tmp=y*z/gcd(y,z);
		ans1-=(a-1)/tmp;
		ans2-=b/tmp;
		tmp=x*z/gcd(x,z);
		ans1-=(a-1)/tmp;
		ans2-=b/tmp;
		tmp=tmp*y/gcd(tmp,y);
		ans1+=(a-1)/tmp;
		ans2+=b/tmp;
		printf("%lld\n",ans2-ans1);
	}
	return 0;
}
