#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=1000;
const int INF=0x3f3f3f3f;

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

char ss[250];

int main(){
	int n,f,d;
	while(scanf("%d%d%d",&n,&f,&d)!=EOF){
		int i,j;
		dinic D;
		D.init(f+2*n+d+5);
		for(i=f+1;i<=f+n;i++){
			D.add(i,i+n,1);
		}
		for(i=1;i<=f;i++){
			int a;
			scanf("%d",&a);
			D.add(0,i,a);
		}
		for(i=1;i<=d;i++){
			int a;
			scanf("%d",&a);
			D.add(f+2*n+i,f+2*n+d+1,a);
		}
		for(i=1;i<=n;i++){
			scanf("%s",ss+1);
			for(j=1;j<=f;j++){
				if(ss[j]=='Y')D.add(j,f+i,1);
			}
		}
		for(i=1;i<=n;i++){
			scanf("%s",ss+1);
			for(j=1;j<=d;j++){
				if(ss[j]=='Y')D.add(f+n+i,f+2*n+j,1);
			}
		}
		printf("%d\n",D.mf(0,f+2*n+d+1));
	}
	return 0;
}
