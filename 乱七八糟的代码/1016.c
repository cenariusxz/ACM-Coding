#include<stdio.h>
#define mod 1000000007
#define mm 166666668
#define ll long long

ll a1[10]={1,1,2,2,3,4,5,6,7,8},s1[10];

int main(){
	ll n;
	while(scanf("%lld",&n)!=EOF){
		n=n/5LL;
		ll m=n/10LL,t=n%10LL;
		ll i,x,y,z,s=0;
		for(i=0;i<=t;i++){
			x=(6*a1[i]+17+3*i)%mod*(m%mod)%mod;
			y=((3*i+27)%mod*(m%mod)%mod)%mod*(m%mod)%mod;
			z=((m%mod)*(m%mod)%mod)*(m%mod)%mod*10%mod;
			s=((s+((x+y+z)%mod)*(mm%mod)%mod)%mod+a1[i])%mod;
		}
		m--;
		for(i=t+1;i<=9;i++){
		
			if(m>=0){
				x=(6*a1[i]+17+3*i)%mod*(m%mod)%mod;
				y=((3*i+27)%mod*(m%mod)%mod)*(m%mod)%mod;
				z=((m%mod)*(m%mod)%mod*10%mod)*(m%mod)%mod;
				s=((s+(((x+y+z)%mod)*(mm%mod)%mod)%mod)%mod+a1[i])%mod;
			}
		}
		printf("%lld\n",s%mod);
	}
	return 0;
}
