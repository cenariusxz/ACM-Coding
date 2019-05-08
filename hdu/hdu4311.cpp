#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF=0x7fffffff;
typedef long long ll;
int x[100000+10],y[100000+10];
ll d[100000+10];

inline ll aabs(ll x){
	return x>=0?x:-x;
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			int n;
			scanf("%d",&n);
			int i,a,b;
			for(i=1;i<=n;i++){
				scanf("%d%d",&x[i],&y[i]);
			}
			sort(x+1,x+n+1);
			sort(y+1,y+n+1);
			ll ans=0;
			for(i=1;i<=n;i++){
				ll tmp=aabs(x[i]-x[n/2+1])+aabs(y[i]-y[n/2+1]);
				ans+=tmp;
			}
			printf("%d %d\n",x[n/2+1],y[n/2+1]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
