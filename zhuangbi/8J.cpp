#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll mod=1e9+7;
const ll X=500000004;
const ll Y=166666668;

ll a[maxn],s[maxn];

void init(){
	a[0]=s[0]=1;
	for(int i=1;i<=100001;++i){
		a[i]=a[i-1]*s[i-1]%mod;
		s[i]=(s[i-1]+a[i])%mod;
	}
}

int main(){
	init();
	int k;
//	printf("%lld %lld\n",a[3],s[1]);
	while(scanf("%d",&k)!=EOF&&k){
		/*
		ll ans1=1,ans2=0;
		for(int i=1;i<=k/2;++i){
			int j=i-1;
			ans2=(ans2*s[j]%mod*s[j]%mod+
				ans1*s[j]%mod*((s[j]-1+mod)%mod)%mod*X%mod)%mod;
			ans1=ans1*s[j]%mod;
		}
		ll ans=(ans1+ans2)%mod;
//		printf("%lld\n",ans);
		if(k%2){
			ans=ans*s[k/2-1]%mod;
//			printf("%lld\n",ans);
			int n=k/2;
			ans=(ans
					+a[n]*((a[n]-1+mod)%mod)%mod*((a[n]-2+mod)%mod)%mod
					+a[n]*((a[n]-1+mod)%mod)%mod
					+a[n]
				)%mod;
			int n=k/2;
			ans=(a[n]+a[n]*((a[n]-1+mod)%mod)*X%mod)%mod;
			ans=(ans*s[n-1]%mod+
					a[n]*((a[n]-1+mod)%mod)%mod*((a[n]-2+mod)%mod)%mod*Y%mod
					+a[n]*((a[n]-1+mod)%mod)%mod*2%mod*X%mod
					+a[n])%mod;
		}
		else{
			int n=k/2;
			ans=(a[n]+a[n]*((a[n]-1+mod)%mod)*X%mod)%mod;
		}
		printf("%lld\n",ans);*/
		printf("%lld %lld\n",a[k],s[k]);
	}
	return 0;
}
