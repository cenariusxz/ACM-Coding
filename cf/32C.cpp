#include<stdio.h>
#include<string.h>
typedef long long ll;

int main(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	ll ans=0;
	ll tmp=(ll)(n/s+(n%s?1:0))*(ll)(m/s+(m%s?1:0));
	if((n%s)==0){
		ans+=tmp*s;
	}
	else ans+=tmp*(n%s);
	if((m%s)==0){
		ans*=s;
	}
	else ans*=(m%s);
	printf("%lld\n",ans);
	return 0;
}
