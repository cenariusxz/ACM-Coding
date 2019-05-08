#include<stdio.h>
#define ll long long
int main(){
	ll a,b;
	scanf("%I64d%I64d",&a,&b);
	ll ans=0;
	while(a!=0&&b!=0){
		if(a<b){
			ll t=a;a=b;b=t;
		}
		ans+=a/b;
		a=((a%b+b)%b);
	}
	printf("%I64d\n",ans);
	return 0;
}
