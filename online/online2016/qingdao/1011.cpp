#include<stdio.h>                //差不多要加这么些头文件
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;

const int maxn=1e4+10;
const int maxm=1e5+5;

int head[maxn],nxt[maxm<<1],val[maxm<<1],point[maxm<<1],size;
int dis[maxn];
int n,m;

struct edge{             //弧的结构体，变量：弧的出发点、结束点、容量、流量
	int from,to,c,f;
	edge(int a,int b,int m,int n):from(a),to(b),c(m),f(n){}
};

struct dinic{
	int m,s,t;                    //边数、源点标号、汇点标号
	vector<edge>e;        //边
	vector<int>g[maxn];    //g[i][j]表示第i个点出发的第j条边在e中的编号
	bool vis[maxn];
	int d[maxn],cur[maxn];    //d为源点到点的距离，cur为当前遍历到的边
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

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b,int c){    //若有向图则只需要前一半
	point[size]=b;
	val[size]=c;
	nxt[size]=head[a];
	head[a]=size++;

	point[size]=a;
	val[size]=c;
	nxt[size]=head[b];
	head[b]=size++;
}

struct cmp{                        //将优先队列改为小根堆
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(){            //传入出发点和到达点
	int s=n;
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dis[u.second])continue;
		for(i=head[u.second];~i;i=nxt[i]){
			int j=point[i];
			if(dis[j]>u.first+1){
				dis[j]=u.first+1;
				q.push(make_pair(dis[j],j));
			}
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		dij();
		dinic D;
		D.init(n);
		for(int s=1;s<=n;++s){
			for(int i=head[s];~i;i=nxt[i]){
				int j=point[i];
				if(1==dis[j]-dis[s])D.add(s,j,val[i]);
			}
		}
		printf("%d\n",D.mf(n,1));
	}
	return 0;
}
