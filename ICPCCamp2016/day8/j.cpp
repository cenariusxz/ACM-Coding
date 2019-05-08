#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;

const int maxn=3e5+5;
const int mod=1e9+7;
typedef long long ll;

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
	int n;
	scanf("%d",&n);
	int n1=0,n2=0,n3=0;
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		if(a==1)n1++;
		else if(a==2)n2++;
		else if(a==3)n3++;
	}
	if(n1!=n3+2){
		printf("0\n");
		return 0;
	}
	if(n3==0){
		ll ans=1;
		for(int i=1;i<=n2;++i)ans=ans*i%mod;
		cout<<ans<<endl;
		return 0;
	}
	ll ans=1;
	for(int i=1;i<=n3;++i){
		ans=ans*i%mod*(2*i-1)%mod;
	}
	if(n2){
		ll res=1;
		ll tmp=1;
		for(int i=1;i<=2*n3+n2;++i){
			tmp=tmp*i%mod;
			if(i==2*n3)res=res*QP(tmp,mod-2)%mod;
		}
		res=res*tmp%mod;
		ans=ans*res%mod;
	}
	cout<<ans<<endl;
	return 0;
}
