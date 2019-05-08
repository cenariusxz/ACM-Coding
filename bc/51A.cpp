#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const ll mod=3221225473;

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int a[3000005];
int vis[3000005];
int v[3000005];

int c[3000005][10];
int cc[3000005][10];
int cnt[3000005];

void init(){
	for(int i=2;i<=3000000;++i){
		if(cnt[i])continue;
		for(int j=1;j*i<=3000000;++j){
			int tmp=j*i;
			c[tmp][++cnt[tmp]]=i;
			int ttmp=tmp;
			while(!(ttmp%i)){
				cc[tmp][cnt[tmp]]++;
				ttmp/=i;
			}
		}
	}
}

ll QP(ll a,ll n){
	ll tmp=a,ans=1;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

int main(){
//	init();
	int T=read();
	while(T--){
		int n=read();
		int i;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;++i)a[i]=read();
		ll ans=1;
		memset(v,0,sizeof(v));
		for(i=1;i<=n;++i){
			if(!vis[i]){
				int pos=i;
				int num=0;
				while(!vis[pos]){
					++num;
					vis[pos]=1;
					pos=a[pos];
				}
				for(int j=1;j<=cnt[num];++j){
					int tmp=c[num][j];
					if(cc[num][j]>v[tmp]){
						v[tmp]=cc[num][j];
					}
				}
			}
		}
		for(i=1;i<=n;++i){
			if(v[i]>1)ans=(ans*QP(i,v[i]))%mod;
			else if(v[i]==1)ans=(ans*i)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
