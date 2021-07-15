#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll f[2000005],g[2000005];
ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%MOD;
		b>>=1;a=a*a%MOD;
	}
	return ret;
}
ll Mul(ll a,ll b){return a*b%MOD;}
ll Add(ll a,ll b){return ((a+b)%MOD+MOD)%MOD;}
ll PopCount(ll x){ll ret=0;while(x){ret+=x&1;x>>=1;}return ret;}
int main() {
	int n;scanf("%d",&n);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),f[x]++;
	for(int j=0;j<20;j++)
	{
		for(int i=(1<<20)-1;~i;i--) if(!((i>>j)&1)) f[i]+=f[i|(1<<j)];
	}
	for(int i = 0 ; i <= 16 ; ++ i)printf("%lld ", f[i]);
    printf("\n");
	for(int i=0;i<(1<<20);i++) g[i]=Add(qpow(2,f[i]),-1);
	for(int i = 0 ; i <= 16 ; ++ i)printf("%lld ", g[i]);
    printf("\n");
	ll Ans=0;
	for(int i=0;i<(1<<20);i++) Ans=Add(Ans,Mul(g[i],PopCount(i)&1?-1:1));
	printf("%lld",Ans);
	return 0;
}
