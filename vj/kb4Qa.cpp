#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
const int maxm=1005;
const int INF=0x3f3f3f3f;

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

int head[1005],point[100005],val[100005],nxt[100005],size;
bool vis[100005];
int dis[1005],n,s,p,fa[1005],pa[1005];


struct edge{             //弧的结构体，变量：弧的出发点、结束点、容量、流量
	int from,to,c,f;
	edge(int a,int b,int m,int n):from(a),to(b),c(m),f(n){}
};

struct dinic{
	int m,s,t;                    //边数、源点标号、汇点标号
	vector<edge>e;        //边
	vector<int>g[maxm];    //g[i][j]表示第i个点出发的第j条边在e中的编号
	bool vis[maxm];
	int d[maxm],cur[maxm];    //d为源点到点的距离，cur为当前遍历到的边
	void init(int n){                //初始化，n为点数量（标号0～n-1）
		for(int i=0;i<n+5;i++)g[i].clear();
		e.clear();
	}
	void add(int a,int b,int v){        //加入弧和反向弧
		e.push_back(edge(a,b,v,0));    //正向弧容量v，反向弧容量0
		e.push_back(edge(b,a,0,0));
		m=e.size();
		g[a].push_back(m-2);
		g[b].push_back(m-1);
	}
	bool bfs(){
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(s);
		d[s]=0;
		vis[s]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<g[u].size();i++){
				edge tmp=e[g[u][i]];
				if(!vis[tmp.to]&&tmp.c>tmp.f){
					vis[tmp.to]=1;
					d[tmp.to]=d[u]+1;
					q.push(tmp.to);
				}
			}
		}
		return vis[t];
	}
	int dfs(int x,int a){
		if(x==t||a==0)return a;
		int flow=0,f;
		for(int& i=cur[x];i<g[x].size();i++){
			edge &tmp=e[g[x][i]];
			if(d[x]+1==d[tmp.to]&&(f=dfs(tmp.to,min(a,tmp.c-tmp.f)))>0){
				tmp.f+=f;
				e[g[x][i]^1].f-=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		if(!flow)d[x]=-1;
		return flow;
	}
	int mf(int s,int t){                //在主函数中使用的函数，求s到t的最大流
		this->s=s;
		this->t=t;
		int flow=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,INF);
		}
		return flow;
	}
};

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

void dij(){
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	memset(dis,0x3f,sizeof(dis));
	memset(fa,-1,sizeof(fa));
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dis[u.second])continue;
		for(i=head[u.second];~i;i=nxt[i]){
			int j=point[i],v=u.first+val[i];
			if(!vis[i]&&dis[j]>v){
				dis[j]=v;
				fa[j]=u.second;
				pa[j]=i;
				q.push(make_pair(dis[j],j));
			}
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		int m,i;
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		size=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			if(a!=b){
				add(a,b,v);
			}
		}
		scanf("%d%d",&s,&p);
		dinic d;
		dij();
		for(i=1;i<=n;++i){
			for(int j=head[i];~j;j=nxt[j]){
				int k=point[j];
				if(dis[i]+val[j]==dis[k])d.add(i,k,1);
			}
		}
		printf("%d\n",d.mf(s,p));
	}
	return 0;
}
