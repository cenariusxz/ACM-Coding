#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=5e6+5;

ll num[maxn];
ll tmp[maxn];
bool vis[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		ll a,b;
		scanf("%d%lld%lld",&n,&a,&b);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i)scanf("%lld",&num[i]);
		sort(num+1,num+n+1);
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				tmp[++cnt]=num[i];
				vis[i]=1;
			}
			if(cnt==3)break;
		}
		for(int i=n;i>=1;--i){
			if(!vis[i]){
				tmp[++cnt]=num[i];
				vis[i]=1;
			}
			if(cnt==6)break;
		}
		int minn=0x7fffffff;
		int p=0;
		for(int i=1;i<=n;++i){
			if(!vis[i]&&abs(num[i])<minn){
				minn=abs(num[i]);
				p=i;
			}
		}
		for(int i=p;i>=1;--i){
			if(!vis[i]){
				tmp[++cnt]=num[i];
				vis[i]=1;
			}
			if(cnt==9)break;
		}
		for(int i=p+1;p<=n;++i){
			if(!vis[i]){
				tmp[++cnt]=num[i];
				vis[i]=1;
			}
			if(cnt==12)break;
		}
		ll ans=-0x7fffffffffffffff;
		for(int i=1;i<=cnt;++i){
			for(int j=1;j<=cnt;++j){
				if(i==j)continue;
				if(a*tmp[i]*tmp[i]+b*tmp[j]>ans)ans=a*tmp[i]*tmp[i]+b*tmp[j];
			}
		}
		printf("Case #%d: %lld\n",q,ans);
	}
	return 0;
}
