#include<stdio.h>
#include<string.h>
typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
	ll a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		if(a>b){
			int t=a;
			a=b;b=t;
		}
		ll tmp1=a;
		while(1){
			if(!(a%tmp1)&&!(b%tmp1))break;
			tmp1--;
		}
		ll tmp2=b;
		while(1){
			if(!(tmp2%a)&&!(tmp2%b))break;
			tmp2++;
		}
		printf("%lld\n",tmp2-tmp1);
	}
	return 0;
}
