#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=505;
int g[maxn][maxn],match[maxn],lx[maxn],ly[maxn],visx[maxn],visy[maxn],s[maxn],n,m;
bool hungary(int u){
	visx[u]=1;
	for(int i=1;i<=n;++i){
		if(!visy[i]&&lx[u]+ly[i]==g[u][i]){
			visy[i]=1;
			if(!match[i]||hungary(match[i])){
				match[i]=u;
				return 1;
			}
		}
		else if(!visy[i])s[i]=min(s[i],lx[u]+ly[i]-g[u][i]);
	}
	return 0;
}
int KM(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)s[j]=INF;
		while(1){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(hungary(i))break;
			int d=INF;
			for(int j=1;j<=n;++j)
				if(!visy[j])d=min(d,s[j]);
			for(int j=1;j<=n;++j){
				if(visx[j])lx[j]-=d;
				if(visy[j])ly[j]+=d;
				else s[j]-=d;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)ans+=g[match[i]][i];
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(lx,0,sizeof(lx));
		memset(ly,0,sizeof(ly));
		memset(match,0,sizeof(match));
		memset(g,0xc0,sizeof(g));
		for(int i=1;i<=m;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			if(-v>g[a][b])g[a][b]=-v;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				lx[i]=max(lx[i],g[i][j]);
			}
		}
		printf("%d\n",-KM());
	}
	return 0;
}
