#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=4e4+5;
const int maxm=8e4+5;
const int maxq=205;

int n;
int head[maxn],nxt[maxm],point[maxm],val[maxm],size;
int vis[maxn],fa[maxn],dis[maxn];
int ans[maxq];
vector<pair<int,int> >v[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		v[i].clear();
		fa[i]=i;
	}
	dis[1]=0;
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
			Tarjan(j,s);
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
			ans[id]=dis[s]+dis[j]-2*dis[lca];
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d%d",&n,&k);
		init();
		for(int i=1;i<n;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		for(int i=1;i<=k;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(make_pair(b,i));
			v[b].push_back(make_pair(a,i));
		}
		Tarjan(1,0);
		for(int i=1;i<=k;++i)printf("%d\n",ans[i]);
	}
}
