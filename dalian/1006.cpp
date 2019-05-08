#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int maxn=1e5;
int c[200005];
int size;

ll A[maxn+5],AA[maxn+5];        //A是阶乘数组，AA是阶乘逆元数组

ll QP(ll a,ll n){
	ll ans=1,tmp=a;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

void init(){
	A[0]=AA[0] = 1;
	for(int i=1;i<=maxn;++i)A[i]=A[i-1]*i%mod;
	//	for(int i=1;i<=maxn;++i)AA[i]=QP(A[i],mod-2);
	AA[maxn]=QP(A[maxn],mod-2);
	for(int i=maxn;i>=1;--i)AA[i-1]=AA[i]*i%mod;
	c[0]=0;
	c[1]=1;
	c[2]=2+3;
	size=2;
	while(1){
		size++;
		c[size]=c[size-1]+size+1;
		if(c[size]>1000000000)break;
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		int l=1,r=size;
		int k=size+1;
		while(l<=r){
			int m=l+((r-l)>>1);
			if(c[m]>x){
				k=min(k,m);
				r=m-1;
			}
			else l=m+1;
		}
		k--;
		ll X=(x-(1+k)*(ll)k/2)/k;
		ll sum=(1+k)*(ll)k/2+X*k;
		ll num=x-sum;
		ll ans=1;ll t=k-num;
		ans=A[t+X]*AA[X]%mod*A[k+1+X]%mod*AA[t+1+X]%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
