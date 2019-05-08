#include<stdio.h>
#define ll long long 
/*
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
*/
int main(){
	ll a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		ll t;

		while(b){
			t=a%b;
			a=b;
			b=t;
		}

		printf("%lld\n",a);
	//	printf("%lld\n",gcd(a,b));
	//	printf("%lld\n",a>b?gcd(a,b):gcd(b,a));
	}
	return 0;
}
