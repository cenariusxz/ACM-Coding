#include<stdio.h>

typedef long long ll;

int main(){
	ll n,m,a;
	scanf("%I64d%I64d%I64d",&n,&m,&a);
	ll x=n/a+((n%a)?1:0);
	ll y=m/a+((m%a)?1:0);
	printf("%I64d\n",x*y);
	return 0;
}
