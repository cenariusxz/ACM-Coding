#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e6+5;

struct seg{
	int a,b;
	ll v;
	bool operator <(const seg x)const{
		return v>x.v;
	}
}s[maxn];

int fa[maxn];
ll sz[maxn];
ll ma[maxn],ans;
int n;

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void unio(int i){
	int x=s[i].a,y=s[i].b;
	ll v=s[i].v;
	int X=find(x),Y=find(y);
	ll nx=ma[X]+v*sz[Y];
	ll ny=ma[Y]+v*sz[X];
	if(nx>=ny){
		fa[Y]=X;
		sz[X]+=sz[Y];
		ma[X]=nx;
		if(nx>ans)ans=nx;
	}
	else{
		fa[X]=Y;
		sz[Y]+=sz[X];
		ma[Y]=ny;
		if(ny>ans)ans=ny;
	}
}

void init(){
	ans=0;
	for(int i=0;i<=n+5;++i)fa[i]=i;
	for(int i=0;i<=n+5;++i)sz[i]=1;
	for(int i=0;i<=n+5;++i)ma[i]=0;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==1){printf("0\n");continue;}
		init();
		for(int i=1;i<n;++i)scanf("%d%d%lld",&s[i].a,&s[i].b,&s[i].v);
		sort(s+1,s+n-1+1);
		for(int i=1;i<n;++i)unio(i);
		printf("%lld\n",ans);
	}
	return 0;
}
