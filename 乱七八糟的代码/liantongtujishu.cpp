#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e3+5;
const int mod=1e9+7;

ll C[maxn][maxn];		//组合数
ll F[maxn],G[maxn],H[maxn];

ll QP(ll a,ll n){		//快速幂
	ll tmp=a,ans=1;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

void init(){
	for(int i=1;i<maxn;++i)H[i]=QP(2,i*(ll)(i-1)/2);
	for(int i=0;i<maxn;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i&&j)?(C[i-1][j]+C[i-1][j-1])%mod:1;
		}
	}
	F[1]=1;G[1]=1;
	for(int i=2;i<maxn;++i){
		G[i]=0;
		for(int k=1;k<i;++k){
			G[i]=(G[i]+C[i-1][k-1]*F[k]%mod*H[i-k]%mod)%mod;
		}
		F[i]=((H[i]-G[i])%mod+mod)%mod;
	}
}

int main(){
	init();
	return 0;
}
