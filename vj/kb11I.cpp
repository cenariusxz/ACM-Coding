#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=1000;
const int INF=0x7fffffff;

struct edge{
	int from,to,f;
	edge(int a,int b,int c):from(a),to(b),f(c){}
};

struct dinic{
	int s,t,m;
	vector<edge>e;
	vector<int>g[maxm];
	bool vis[maxm];
	int cur[maxm],d[maxm];

	void init(int n){
		for(int i=1;i<=n;i++)g[i].clear();
		e.clear();
	}

	void add(int a,int b,int c){
		e.push_back(edge(a,b,c));
		e.push_back(edge(b,a,0));
		m=e.size();
		g[a].push_back(m-2);
		g[b].push_back(m-1);
	}

	bool bfs(){
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(s);
		vis[s]=1;
		d[s]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<g[u].size();i++){
				edge tmp=e[g[u][i]];
				if(!vis[tmp.to]&&tmp.f>0){
					d[tmp.to]=d[u]+1;
					vis[tmp.to]=1;
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
			edge& tmp=e[g[x][i]];
			if(d[tmp.to]==d[x]+1&&tmp.f>0){
				f=dfs(tmp.to,min(a,tmp.f));
				tmp.f-=f;
				e[g[x][i]^1].f+=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		if(flow==0)d[x]=-1;
		return flow;
	}

	int mf(int s,int t){
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

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		dinic d;
		d.init(2*n+10);
		int a,b;
		scanf("%d%d",&a,&b);
		d.add(0,a,INF);
		d.add(b+n,2*n+1,INF);
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			d.add(i,i+n,a);
		}
		for(i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			d.add(a+n,b,INF);
			d.add(b+n,a,INF);
		}
		printf("%d\n",d.mf(0,2*n+1));
	}
	return 0;
}

