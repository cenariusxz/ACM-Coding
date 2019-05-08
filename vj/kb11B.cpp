#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=410;
const int INF=0x3f3f3f3f;

struct edge{
	int from,to,c,f;
	edge(int a,int b,int m,int n):from(a),to(b),c(m),f(n){}
};

struct dinic{
	int m,s,t;
	vector<edge>e;
	vector<int>g[maxm];
	int cur[maxm],d[maxm];
	bool vis[maxm];

	void init(int n){
		for(int i=0;i<=n;i++)g[i].clear();
		e.clear();
	}

	void add(int a,int b){
		e.push_back(edge(a,b,1,0));
		e.push_back(edge(b,a,0,0));
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
			int u=q.front();q.pop();
			for(int i=0;i<g[u].size();i++){
				edge tmp=e[g[u][i]];
				if(!vis[tmp.to]&&tmp.c>tmp.f){
					q.push(tmp.to);
					vis[tmp.to]=1;
					d[tmp.to]=d[u]+1;
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
			if(d[tmp.to]==d[x]+1&&(f=dfs(tmp.to,min(a,tmp.c-tmp.f)))>0){
				tmp.f+=f;
				e[g[x][i]^1].f-=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		if(flow==0)d[x]=-1;
		return flow;
	}

	int mf(int s,int t){
		this->s=s;this->t=t;
		int flow=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,INF);
		}
		return flow;
	}
};

int main(){
	int n,f,d,i,j;
	scanf("%d%d%d",&n,&f,&d);
	dinic D;
	D.init(f+d+1+2*n);
	for(i=1;i<=f;i++)D.add(0,i);
	for(i=f+1+2*n;i<=f+2*n+d;i++)D.add(i,f+d+1+2*n);
	for(i=f+1;i<=f+n;i++)D.add(i,i+n);
	for(i=1;i<=n;i++){
		int a,b,v;
		scanf("%d%d",&a,&b);
		for(j=1;j<=a;j++){
			scanf("%d",&v);
			D.add(v,f+i);
		}
		for(j=1;j<=b;j++){
			scanf("%d",&v);
			D.add(f+n+i,f+2*n+v);
		}
	}
	printf("%d\n",D.mf(0,f+d+1+2*n));
	return 0;
}
