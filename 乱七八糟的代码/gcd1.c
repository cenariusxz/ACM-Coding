#include<stdio.h>
#define ll long long

ll gcd(ll a,ll b,ll &d,ll& x,ll& y){
	if(!b){
		d=a;
		x=1;
		y=0;
		return x;
	}
	else{
		gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
	return x;
}

int main(){
	ll a,b,d,x,y;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		x=gcd(a,b,d,x,y);
		printf("a:%lld->x:%lld\n",a,x);
//		printf("a:%lld->x:%lld\nb:%lld->y:%lld\n",a,x,b,y);
	}
	return 0;
}
