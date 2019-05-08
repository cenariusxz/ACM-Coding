#include<stdio.h>
#include<string.h>
typedef long long ll;

ll gcd(ll a,ll b){
	for(;a>0&&b>0;a>b?a%=b:b%=a);
	return a+b;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll a,b,n;
		scanf("%lld%lld%lld",&n,&a,&b);
		ll k=(n+1)%a;
		ll lcm=a*b/gcd(a,b);
		ll ans=(n+1-k)/lcm-(b-k)/lcm;
		if(!((b-k)%lcm))ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
