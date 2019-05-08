#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

inline ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

int vis[10005];
ll a[10005];
ll cop[10005];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		ll m;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		for(int i=1;i<=n;++i){
			vis[i]=1;
			cop[i]=gcd(a[i],m);
		}
		sort(cop+1LL,cop+(ll)n+1LL);
		int t=1;
		for(int i=2;i<=n;++i){
			if(cop[i]!=cop[i-1])cop[++t]=cop[i];
		}
		for(int i=1;i<t;++i){
			if(vis[i]){
				for(int j=i+1;j<=t;++j){
					if(vis[j]){
						if(!(cop[j]%cop[i]))vis[j]=0;
					}
				}
			}
		}
		int cnt=1;
		for(int i=2;i<=t;++i){
			if(vis[i])cop[++cnt]=cop[i];
		}
		ll ans=0;
		m--;
		if(cnt>=31)while(1){};
		for(ll i=1;i<(1ll<<cnt);++i){
			ll mul=1;
			int bit=0;
			for(int j=1;j<=cnt;++j){
				if(i&(1<<(j-1))){
					bit++;
					mul=mul/gcd(mul,cop[j])*cop[j];
				}
			}
			ll tmp=m/mul;
			if(bit%2)ans+=tmp*(tmp+1)/2*mul;
			else ans-=tmp*(tmp+1)/2*mul;
		}
		printf("Case #%d: %lld\n",q,(ll)ans);
	}
	return 0;
}
