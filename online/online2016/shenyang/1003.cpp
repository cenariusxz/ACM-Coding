#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAXN=1e6+5;

int fac[MAXN],afac[MAXN];

int Q_pow(int x,int y){
	int res = 1;
	while(y){
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res % mod; //小心模数为1的情况
}

void Pre(){
	fac[0] = afac[0] = 1;
	for(int i = 1; i < MAXN; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
	afac[MAXN - 1] = Q_pow(fac[MAXN - 1],mod - 2);
	for(int i = MAXN - 1; i > 1; --i) afac[i - 1] = 1ll * afac[i] * i % mod;
}

ll C(int m,int n){
	return fac[m]*(ll)afac[n]%mod*(ll)afac[m-n]%mod;
}

int main(){
	int T;
	Pre();
	scanf("%d",&T);
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		if(m==1)printf("%d\n",n);
		else if(m*(k+1)>n)printf("0\n");
		else{
			ll ans=k*C(n-m*k-1,m-1)%mod+C(n-m*k,m);
			ans%=mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
