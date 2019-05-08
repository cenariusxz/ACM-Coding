#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=110119;
const int maxn=1e5+5;

struct Node{
	ll x,y;
	bool operator <(const Node a)const{
		if(x==a.x)return y<a.y;
		else return x<a.x;
	}
}node[10000];

ll dp[10000];
ll res[10000];
ll fac[200000],afac[200000];

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
	fac[0]=afac[0]=1;
	for(int i=1;i<=120000;++i)fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=120000;++i)afac[i]=QP(fac[i],mod-2);
}

ll C(ll a,ll b){
	if(a<b)return 0;
	if(a==b)return 1;
	if(b>a-b)b=a-b;
	return fac[a]*afac[a-b]%mod*afac[b]%mod;
}

ll lucas(ll a,ll b){
	ll ans=1;
	while(a&&b&&ans){
		ans=(ans*C(a%mod,b%mod)%mod);
		a/=mod;
		b/=mod;
	}
	return ans;
}

ll cal(ll a,ll b){
	a--;b--;
	if(2*b-a<0||2*a-b<0)return 0;
	if((2*b-a)%3!=0||(2*a-b)%3!=0)return 0;
	ll x=(2*a-b)/3,y=(2*b-a)/3;
	return lucas(x+y,x);
}

int main(){
	ll n,m;
	int r;
	int cnt=0;
	init();
	while(scanf("%lld%lld%d",&n,&m,&r)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=r;++i){
			scanf("%lld%lld",&node[i].x,&node[i].y);
		}
		sort(node+1,node+r+1);
		for(int i=r;i>=1;--i){
			dp[i]=cal(n-node[i].x+1,m-node[i].y+1);
			for(int j=i+1;j<=r;++j){
				if(node[j].x<=node[i].x||node[j].y<=node[i].y)continue;
				dp[i]-=cal(node[j].x-node[i].x+1,node[j].y-node[i].y+1)*dp[j]%mod;
				dp[i]=(dp[i]%mod+mod)%mod;
			}
		}
		ll ans=0;
		ans=cal(n,m);
		for(int i=1;i<=r;++i){
			if(node[i].x>1&&node[i].y>1){
				ans-=cal(node[i].x,node[i].y)*dp[i]%mod;
				ans=(ans%mod+mod)%mod;
			}
		}
		printf("Case #%d: %lld\n",++cnt,ans);
	}
	return 0;
}
