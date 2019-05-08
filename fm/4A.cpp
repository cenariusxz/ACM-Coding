#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=4e4+5;
const int maxm=8e4+5;
const int maxl=20;		//总点数的log范围，一般会开稍大一点

int fa[maxl][maxn],dep[maxn],dis[maxn];		//fa[i][j]是j点向上（不包括自己）2**i 层的父节点，dep是某个点的深度（根节点深度为0），dis是节点到根节点的距离
int head[maxn],point[maxm],nxt[maxm],val[maxm],size,n;

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

void Dfs(int s,int pre,int d){		//传入当前节点标号，父亲节点标号，以及当前深度
	fa[0][s]=pre;					//当前节点的上一层父节点是传入的父节点标号
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
	for(int k=0;k+1<maxl;++k){		//类似RMQ的做法，处理出点向上2的幂次的祖先。
		for(int v=1;v<=n;++v){
			if(fa[k][v]<0)fa[k+1][v]=-1;
			else fa[k+1][v]=fa[k][fa[k][v]];	//处理出两倍距离的祖先
		}
	}
}

int Lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);		//定u为靠近根的点
	for(int k=maxl-1;k>=0;--k){
		if((dep[v]-dep[u])&(1<<k))	//根据层数差值的二进制向上找v的父亲
			v=fa[k][v];
	}
	if(u==v)return u;				//u为v的根
	for(int k=maxl-1;k>=0;--k){
		if(fa[k][u]!=fa[k][v]){		//保持在相等层数，同时上爬寻找相同父节点
			u=fa[k][u];
			v=fa[k][v];
		}
	}
	return fa[0][u];				//u离lca只差一步
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<n;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		Pre();
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			int num=Lca(a,b);
			printf("%d\n",dis[a]+dis[b]-2*dis[num]);
		}
	}
	return 0;
}
