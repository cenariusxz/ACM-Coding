#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=2000;
const int INF=0x3f3f3f3f;

int read(){
	 int x=0;
	 char c=getchar();
	 while(c<'0'||c>'9')c=getchar();
	 while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	 }
	 return x;
}

struct edge{
	int from,to,c,f;
	edge(int a,int b,int m,int n):from(a),to(b),c(m),f(n){}
};

struct dinic{
	int s,t,m;
	vector<edge>e;
	vector<int>g[maxm];
	int cur[maxm],d[maxm];
	bool vis[maxm];

	void init(int n){
		for(int i=0;i<=n;i++)g[i].clear();
		e.clear();
	}

	void add(int a,int b,int c){
		e.push_back(edge(a,b,c,0));
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
			int u=q.front();
			q.pop();
			for(int i=0;i<g[u].size();i++){
				edge tmp=e[g[u][i]];
				if(!vis[tmp.to]&&tmp.c>tmp.f){
					d[tmp.to]=d[u]+1;
					q.push(tmp.to);
					vis[tmp.to]=1;
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
	int n,np,nc,m;
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF){
		int i,j;
		int a,b,c;
		dinic d;
		d.init(maxm-50);
		for(i=1;i<=m;i++){
			a=read();
			b=read();
			c=read();
			d.add(a,b,c);
		}
		for(i=1;i<=np;i++){
			a=read();
			b=read();
			d.add(1500,a,b);
		}
		for(i=1;i<=nc;i++){
			a=read();
			b=read();
			d.add(a,1501,b);
		}
		printf("%d\n",d.mf(1500,1501));
	}
	return 0;
}
