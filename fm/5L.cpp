#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

ll QP(ll a,ll n){
	ll ans=1,tmp=a;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

ll getsum(ll n){
	return n*(n+1)%mod*(2*n+1)%mod*((n*n*3%mod+n*3%mod-1+mod)%mod)%mod*QP(30,mod-2)%mod;
}

int pnum[50],num;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		num=0;
		int tmp=n;
		for(int i=2;i*(ll)i<=tmp;++i){
			if(!(tmp%i)){
				pnum[++num]=i;
				while(!(tmp%i))tmp/=i;
			}
		}
		if(tmp-1)pnum[++num]=tmp;
		ll ans=0;
		for(int i=1;i<(1<<num);++i){
			int bit=0;
			int mul=1;
			for(int j=1;j<=num;++j){
				if(i&(1<<(j-1))){
					bit++;
					mul*=pnum[j];
				}
			}
			if(bit%2)ans=(ans+QP(mul,4)*getsum(n/mul)%mod)%mod;
			else ans=(ans-QP(mul,4)*getsum(n/mul)%mod)%mod;
		}
		printf("%lld\n",((getsum(n)-ans)%mod+mod)%mod);
	}
	return 0;
}
