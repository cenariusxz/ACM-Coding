#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
const int maxm=2e5+5;
const int maxl=20;
const int INF=0x3f3f3f3f;

int fa[maxl][maxn],dep[maxn];
int head[maxn],point[maxm],nxt[maxm],size;
int stx[maxn],edx[maxn],ti;
int st[maxn<<2],add[maxn<<2];
int val[maxn];
int n,m,sec,cnt;

struct seg{
	int y1,y2,x,c;
	bool operator <(const seg a)const{
		return x<a.x;
	}
}s[maxm<<2];

void init(){
	size=0;ti=0;cnt=0;
	memset(head,-1,sizeof(head));
	memset(val,0,sizeof(val));
}

void Dfs(int s,int pre,int d){
	fa[0][s]=pre;
	dep[s]=d;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==pre)continue;
		Dfs(j,s,d+1);
	}
}

void Pre(){
	Dfs(1,-1,0);
	for(int k=0;k+1<maxl;++k){
		for(int v=1;v<=n;++v){
			if(fa[k][v]<0)fa[k+1][v]=-1;
			else fa[k+1][v]=fa[k][fa[k][v]];
		}
	}
}

int Lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	int uu=u,vv=v;
	for(int k=maxl-1;k>=0;--k){
		if((dep[v]-dep[u])&(1<<k))
			v=fa[k][v];
	}
	if(u==v){
		for(int k=maxl-1;k>=0;--k){
			if((dep[vv]-(dep[uu]+1))&(1<<k))vv=fa[k][vv];
		}
		sec=vv;
		return u;
	}
	for(int k=maxl-1;k>=0;--k){
		if(fa[k][u]!=fa[k][v]){
			u=fa[k][u];
			v=fa[k][v];
		}
	}
	sec=u;
	return fa[0][u];
}

void adde(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void build(){
	memset(st,0,sizeof(st));
	memset(add,0,sizeof(add));
}

void pushdown(int o){
	if(add[o]){
		add[o<<1]+=add[o];
		add[o<<1|1]+=add[o];
		st[o<<1]+=add[o];
		st[o<<1|1]+=add[o];
		add[o]=0;
	}
}

void update(int o,int l,int r,seg a){
	if(a.y1<=l&&a.y2>=r){
		add[o]+=a.c;
		st[o]+=a.c;
		return;
	}
	pushdown(o);
	int m=l+((r-l)>>1);
	if(a.y1<=m)update(o<<1,l,m,a);
	if(a.y2>=m+1)update(o<<1|1,m+1,r,a);
	st[o]=max(st[o<<1],st[o<<1|1]);
}

void dfs(int s,int f){
	stx[s]=++ti;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==f)continue;
		dfs(j,s);
	}
	edx[s]=ti;
}

void addseg(int x1,int x2,int y1,int y2,int c){
	++cnt;
	s[cnt].x=x1;
	s[cnt].y1=y1;
	s[cnt].y2=y2;
	s[cnt].c=c;
	++cnt;
	s[cnt].x=x2+1;
	s[cnt].y1=y1;
	s[cnt].y2=y2;
	s[cnt].c=-c;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			adde(a,b);
			adde(b,a);
		}
		dfs(1,-1);
		Pre();
		int ans=0;
		for(int i=1;i<=m;++i){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			int lca=Lca(u,v);
			if(lca!=u&&lca!=v)addseg(stx[v],edx[v],stx[u],edx[u],w);
			else if(lca==u&&lca!=v){
				if(stx[sec]!=1)addseg(stx[v],edx[v],1,stx[sec]-1,w);
				if(edx[sec]!=ti)addseg(stx[v],edx[v],edx[sec]+1,ti,w);
			}
			else if(lca==v&&lca!=u){
				if(stx[sec]!=1)addseg(1,stx[sec]-1,stx[u],edx[u],w);
				if(edx[sec]!=ti)addseg(edx[sec]+1,ti,stx[u],edx[u],w);
			}
			else  if(u==v){
				ans+=w;
				val[u]+=w;
			}
		}
		for(int u=1;u<=n;++u){
			if(val[u]){
				if(fa[0][u]!=-1){
					addseg(1,stx[u]-1,1,stx[u]-1,-val[u]);
					addseg(1,stx[u]-1,edx[u]+1,ti,-val[u]);
					addseg(edx[u]+1,ti,1,stx[u]-1,-val[u]);
					addseg(edx[u]+1,ti,edx[u]+1,ti,-val[u]);
				}
				for(int k=head[u];~k;k=nxt[k]){
					int j=point[k];
					if(j==fa[0][u])continue;
					addseg(stx[j],edx[j],stx[j],edx[j],-val[u]);
				}
			}
		}
		sort(s+1,s+cnt+1);
		build();
		int maxx=-INF;
		for(int i=1;i<=cnt;++i){
			update(1,0,ti,s[i]);
			if(s[i].x!=s[i+1].x&&st[1]>maxx)maxx=st[1];
		}
		printf("Case #%d: %d\n",q,ans+maxx);
	}
	return 0;
}
