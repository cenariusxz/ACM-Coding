#include<stdio.h>
#include<string.h>
const int maxn=1e5+5;
const int maxm=1e5+5;
const int maxl=18;		//总点数的log范围，一般会开稍大一点

int fa[2][maxl][maxn],dep[2][maxn];		//fa[i][j]是j点向上（不包括自己）2**i 层的父节点，dep是某个点的深度（根节点深度为0），dis是节点到根节点的距离
int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
//0 wife 1 hus
int n,m;

void init(){
	size[0]=size[1]=0;
	memset(head,-1,sizeof(head));
}

void add(int a,int b,int c){
	point[c][size[c]]=b;
	nxt[c][size[c]]=head[c][a];
	head[c][a]=size[c]++;
}

void Dfs(int s,int d,int c){
	dep[c][s]=d;
	for(int i=head[c][s];~i;i=nxt[c][i]){
		int j=point[c][i];
		Dfs(j,d+1,c);
	}
}

int Lca(int u,int v){
	if(u==v)return u;
	int a[2];
	a[0]=u;		//wife
	a[1]=v;		//hus
	int x=0;
	if(a[0]<a[1])x=1;
	else x=0;
	while(a[0]!=a[1]){
		int l=0,r=(maxl-1)*2;
		while(l<=r){
			int m=l+((r-l)>>1);
			if(fa[x][m][a[x]]==a[x^1])return a[x^1];
			if(fa[x][m][a[x]]>a[x^1]){
				a[x]=fa[x][m][a[x]];
			}
			r=m-1;
		}
		a[x]=fa[x][0][a[x]];
		if(a[x]==a[x^1])return a[x];
		if(a[x]<a[x^1])x^=1;
	}
	return a[0];
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
	int q;
	while(scanf("%d%d",&n,&q)!=EOF){
		init();
		fa[0][0][1]=-1;
		fa[1][0][1]=-1;
		for(int i=2;i<=n;++i){
			int a;
			a=read();
			add(a,i,0);
			fa[0][0][i]=a;
		}
		for(int i=2;i<=n;++i){
			int a;
			a=read();
			add(a,i,1);
			fa[1][0][i]=a;
		}
		Dfs(1,0,0);
		Dfs(1,0,1);
		for(int k=0;k+1<maxl;++k){
			for(int v=1;v<=n;++v){
				if(fa[0][k][v]<0)fa[0][k+1][v]=-1;
				else fa[0][k+1][v]=fa[0][k][fa[0][k][v]];
				if(fa[1][k][v]<0)fa[1][k+1][v]=-1;
				else fa[1][k+1][v]=fa[1][k][fa[0][k][v]];
			}
		}
		int k=0;
		while(q--){
			int a=read();
			int b=read();
			a=(a+k)%n +1;
			b=(b+k)%n +1;
			k=Lca(a,b);
			printf("%d %d %d\n",k,dep[0][a]-dep[0][k]+1,dep[1][b]-dep[1][k]+1);
		}
	}
	return 0;
}
