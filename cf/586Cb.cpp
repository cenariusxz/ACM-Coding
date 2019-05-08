#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

ll v[4005],d[4005],p[4005];
int vis[4005];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld%lld%lld",&v[i],&d[i],&p[i]);
	memset(vis,0,sizeof(vis));
	int ans=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			if(p[i]>=0){
				vis[i]=1;
				ans++;
				for(int j=i+1;j<=n;++j){
					p[j]-=v[i];
					v[i]--;
					if(v[i]<=0)break;
				}
			}
			else{
				for(int j=i+1;j<=n;++j){
					p[j]-=d[i];
				}
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		if(vis[i])printf("%d ",i);
	}
	printf("\n");
	return 0;
}
