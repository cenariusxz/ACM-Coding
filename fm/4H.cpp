#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int maxl=20;

int fa[maxl][maxn],dep[maxn],dis[maxn];
int head[maxn],point[maxm],nxt[maxm],val[maxm],size;
int n;

void init(){
	size=0;
	memset(head,-1,sizeof(head));
}

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	val[size]=v;
	nxt[size]=head[b];
	head[b]=size++;
}

void Dfs(int s,int pre,int d){
	fa[0][s]=pre;
	dep[s]=d;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==pre)continue;
		dis[j]=dis[s]+val[i];
		Dfs(j,s,d+1);
	}
}

void Pre(){
	dis[1]=0;
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
	for(int k=maxl-1;k>=0;--k){
		if((dep[v]-dep[u])&(1<<k))
			v=fa[k][v];
	}
	if(u==v)return u;
	for(int k=maxl-1;k>=0;--k){
		if(fa[k][u]!=fa[k][v]){
			u=fa[k][u];
			v=fa[k][v];
		}
	}
	return fa[0][u];
}

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

int main(){
	int m;
	scanf("%d%d",&n,&m);
	init();
	while(m--){
		int a,b,v;
		a=read();
		b=read();
		v=read();
		add(a,b,v);
	}
	Pre();
	int q=read();
	while(q--){
		int a=read();
		int b=read();
		int lca=Lca(a,b);
		printf("%d\n",dis[a]+dis[b]-2*dis[lca]);
	}
	return 0;
}
