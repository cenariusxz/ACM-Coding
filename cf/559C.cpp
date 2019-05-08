#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxm=200000;

ll fac[maxm+10],afac[maxm+10];

ll QP(ll a,ll b,ll mod){
	ll tmp=a,ans=1;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

void init(){
	fac[0]=1;
	for(int i=1;i<=maxm;++i)fac[i]=fac[i-1]*(ll)i%mod;
	afac[maxm]=QP(fac[maxm],mod-2);
	for(int i=maxm;i>=1;--i)afac[i-1]=afac[i]*i%mod;
}

int main(){
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	
	return 0;
}
