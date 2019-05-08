#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=1e9+7;
const int maxm=1e6+1;

int a[maxm+5];
int prime[78520];
bool vis[maxm+5];

ll QP(ll a,ll n){
	ll tmp=a,ans=1;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

void init(){
	int cnt=0;
	for(int i=2;i<=maxm;++i){
		if(!vis[i]){
			prime[cnt++]=i;
			ll tmp=i;
			while(tmp<maxm){
				a[tmp]=i;
				tmp*=i;
			}
		}
		for(int j=0;j<cnt&&i*(ll)prime[j]<=maxm;++j){
			vis[i*prime[j]]=1;
			if(!(i%prime[j]))break;
		}
	}
	a[1]=1;
	for(int i=2;i<=maxm;++i){
		if(a[i])a[i]=a[i-1]*(ll)a[i]%mod;
		else a[i]=a[i-1];
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",a[n+1]*QP(n+1,mod-2)%mod);
	}
	return 0;
}
