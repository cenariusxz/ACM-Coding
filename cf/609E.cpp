#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;
const int maxl=20;        //总点数的log范围，一般会开稍大一点

struct seg{
	int a,b,v,num;
	bool operator < (const seg x)const{
		return v<x.v;
	}
}s[maxn];

int head[maxn],nxt[maxn<<1],point[maxn<<1],val[maxn<<1],size;
int Fa[maxn];
int fa[maxl][maxn],dep[maxn];        //fa[i][j]是j点向上（不包括自己）2**i 层的父节点，dep是某个点的深度（根节点深度为0），dis是节点到根节点的距离
int maxx[maxl][maxn];
int n;
ll ans[maxn];

void Dfs(int s,int pre,int d,int v){        //传入当前节点标号，父亲节点标号，以及当前深度
	fa[0][s]=pre;                    //当前节点的上一层父节点是传入的父节点标号
	maxx[0][s]=v;
	dep[s]=d;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==pre)continue;
		Dfs(j,s,d+1,val[i]);
	}
}

void Pre(){
	memset(maxx,-1,sizeof(maxx));
	Dfs(1,-1,0,-1);
	for(int k=0;k+1<maxl;++k){        //类似RMQ的做法，处理出点向上2的幂次的祖先。
		for(int v=1;v<=n;++v){
			if(fa[k][v]<0){
				fa[k+1][v]=-1;
				maxx[k+1][v]=-1;
			}
			else{
				fa[k+1][v]=fa[k][fa[k][v]];    //处理出两倍距离的祖先
				maxx[k+1][v]=max(maxx[k][v],maxx[k][fa[k][v]]);
			}
		}
	}
}

int Lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);        //定u为靠近根的点
//	printf("ccc:%d %d\n",u,v);
	int ans=-1;
	for(int k=maxl-1;k>=0;--k){
		if((dep[v]-dep[u])&(1<<k)){    //根据层数差值的二进制向上找v的父亲
			ans=max(ans,maxx[k][v]);
			v=fa[k][v];
		}
	}
//	printf("aaa:%d\n",ans);
	if(u==v)return ans;                //u为v的根
	for(int k=maxl-1;k>=0;--k){
		if(fa[k][u]!=fa[k][v]){        //保持在相等层数，同时上爬寻找相同父节点
//			printf("kkk:%d %d\n",fa[k][u],fa[k][v]);
			ans=max(ans,maxx[k][u]);
			ans=max(ans,maxx[k][v]);
			u=fa[k][u];
			v=fa[k][v];
		}
	}
//	printf("bbb:%d %d %d\n",ans,u,fa[0][u]);
	return max(ans,max(maxx[0][u],maxx[0][v]));
}

void init(int n){
	memset(head,-1,sizeof(head));
	size=0;
	for(int i=1;i<=n;++i)Fa[i]=i;
}

int find(int x){
	return x==Fa[x]?x:Fa[x]=find(Fa[x]);
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

int main(){
	int m;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].v);
		s[i].num=i;
	}
	sort(s+1,s+m+1);
	ll sum=0;
	for(int i=1;i<=m;++i){
		int x=find(s[i].a),y=find(s[i].b);
		if(x!=y){
			Fa[x]=y;
			add(s[i].a,s[i].b,s[i].v);
			sum+=s[i].v;
		}
	}
	Pre();

	for(int i=1;i<=m;++i){
		int num=Lca(s[i].a,s[i].b);
//		printf("%d ",num);
//		printf("%lld\n",sum-num+s[i].v);
		ans[s[i].num]=sum-num+s[i].v;
	}
	for(int i=1;i<=m;++i)printf("%I64d\n",ans[i]);
	return 0;
}
