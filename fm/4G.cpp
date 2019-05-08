#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=905;
const int maxm=905*2;
const int maxl=20;

int fa[maxl][maxn],dep[maxn];
int head[maxn],point[maxm],nxt[maxm],size;
int vis[maxn];
int ans[maxn];
int n;

void init(){
	size=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
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

void Pre(int i){
	Dfs(i,-1,0);
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
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=1;i<=n;++i){
			int a=read();
			int num=read();
			while(num--){
				int b=read();
				add(a,b);
				vis[b]=1;
			}
		}
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				Pre(i);
				break;
			}
		}
		int q=read();
		while(q--){
			int a=read();
			int b=read();
			ans[Lca(a,b)]++;
		}
		for(int i=1;i<=n;++i){
			if(ans[i])printf("%d:%d\n",i,ans[i]);
		}
	}
	return 0;
}
