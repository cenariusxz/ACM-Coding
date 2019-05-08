#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;
const int maxm=2e5+5;
const int maxl=20;

int fa[maxl][maxn],dep[maxn],dp[maxn];
int head[maxn],point[maxm],nxt[maxm],val[maxm],size;
int n,m;
int ans;

void init(){
	size=0;
	memset(head,-1,sizeof(head));
	memset(dp,0,sizeof(dp));
	ans=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
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

void dfs(int s){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(dep[j]<dep[s])continue;
		dfs(j);
		dp[s]+=dp[j];
	}
	if(s!=1){
		if(dp[s]==0)ans+=m;
		else if(dp[s]==1)ans++;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	Pre();
	for(int i=1;i<=m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		int lca=Lca(a,b);
		dp[a]++;
		dp[b]++;
		dp[lca]-=2;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
