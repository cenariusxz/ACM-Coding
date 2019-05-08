#include<stdio.h>
#include<string.h>
typedef long long ll;

int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll ans=0;
	while(a!=1&&a!=0){
		if(a>b){
			ans+=a/b;
			a%=b;
		}
		else{
			ans+=b/a;
			b%=a;
		}
	}
	if(a==1)ans+=b;
	printf("%lld\n",ans);
	return 0;
}
