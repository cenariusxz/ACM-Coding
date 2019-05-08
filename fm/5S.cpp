#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;

ll QP(ll a,ll n){
	ll ans=1,tmp=a;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

int main(){
	ll k,n;
	while(scanf("%lld%lld",&n,&k)!=EOF){
		ll ans=QP((QP(2,k)-1),n);
		printf("%lld\n",ans);
	}
	return 0;
}
