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
	int a,b,v;
	bool operator < (const seg x)const{
		return v<x.v;
	}
}s[maxn];

int head[maxn],point[maxn],val[maxn],nxt[maxn],size;
int fa[maxn];
int n,m;
ll ans;

void init(int n){
	for(int i=1;i<=n;++i)fa[i]=i;
	memset(head,-1,sizeof(head));
	size=0;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

int dfs(int s,int f,int v){
	int sz=1;
	for(int i=head[s];~i;i=nxt[i]){
		if(point[i]==f)continue;
		sz+=dfs(point[i],s,val[i]);
	}
	ans+=v*(ll)(n-sz)*sz;
	return sz;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			s[i].a=a;
			s[i].b=b;
			s[i].v=v;
		}
		sort(s+1,s+m+1);
		init(n);
		ll sum=0;
		for(int i=1;i<=m;++i){
			int X=find(s[i].a);
			int Y=find(s[i].b);
			if(X!=Y){
				sum+=s[i].v;
				fa[X]=Y;
				add(s[i].a,s[i].b,s[i].v);
				add(s[i].b,s[i].a,s[i].v);
			}
		}
		ans=0;
		dfs(1,-1,0);
		double res=0;
		if(n>1)res=ans*1.0/(n*1.0*(n-1)/2);
		printf("%lld %.2lf\n",sum,res);
	}
	return 0;
}
