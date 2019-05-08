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
		ll a,b;
		scanf("%lld%lld",&a,&b);
		ll g=gcd(a+3*b,4*a+4*b);
		printf("%lld/%lld\n",(a+3*b)/g,(4*a+4*b)/g);
	}
	return 0;
}
