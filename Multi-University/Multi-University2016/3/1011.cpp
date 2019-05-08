#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

int vis[maxn*2];
int xx[maxn],yy[maxn];

inline int aabs(int x){return x>0?x:(-x);}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d%d",&xx[i],&yy[i]);
		if(n*(ll)(n-1)/2>2*m+1){
			printf("YES\n");
			continue;
		}
		memset(vis,0,sizeof(vis));
		bool f=0;
		for(int i=1;i<=n&&!f;++i){
			for(int j=i+1;j<=n&&!f;++j){
				int d=abs(xx[i]-xx[j])+abs(yy[i]-yy[j]);
				if(vis[d])f=1;
				else vis[d]=1;
			}
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
