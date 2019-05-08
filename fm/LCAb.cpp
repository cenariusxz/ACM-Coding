#include<stdio.h>		//差不多要这些头文件
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;	//点数、边数、询问数
const int maxm=2e5+5;
const int maxq=1e4+5;

int n;
int head[maxn],nxt[maxm],point[maxm],val[maxm],size;
int vis[maxn],fa[maxn],dep[maxn],dis[maxn];
int ans[maxq];
vector<pair<int,int> >v[maxn];	//记录询问、问题编号

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		v[i].clear();
		fa[i]=i;
	}
	dis[1]=dep[1]=0;
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

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void Tarjan(int s,int pre){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j!=pre){
			dis[j]=dis[s]+val[i];
			dep[j]=dep[s]+1;
			Tarjan(j,s);				//这里Tarjan的DPS操作必须在并查集合并之前，这样才能保证求lca的时候lca是每一小部分合并时的祖先节点，如果顺序交换，那么所有的查询都会得到 1 节点，就是错误的
			int x=find(j),y=find(s);
			if(x!=y)fa[x]=y;
		}
	}
	vis[s]=1;
	for(int i=0;i<v[s].size();++i){
		int j=v[s][i].first;
		if(vis[j]){
			int lca=find(j);
			int id=v[s][i].second;
			ans[id]=lca;			//这里视题目要求给答案赋值
		//	ans[id]=dep[s]+dep[j]-2*dep[lca];
		//	ans[id]=dis[s]+dis[j]-2*dis[lca];
		}
	}
}

int main(){
	char d;
	int a,b,c;
	int m,k;
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=m;++i){
		scanf("%d%d%d%c",&a,&b,&c,&d);
		add(a,b,c);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;++i){
		scanf("%d%d",&a,&b);
		v[a].push_back(make_pair(b,i));		//加问题的时候两个点都要加一次
		v[b].push_back(make_pair(a,i));
	}
	Tarjan(1,0);
	for(int i=1;i<=k;++i)
		printf("%d\n",ans[i]);
	return 0;
}
