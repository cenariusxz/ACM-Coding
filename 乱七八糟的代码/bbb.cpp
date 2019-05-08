#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxm=700;
const ll INF=5001001000010;

struct edge{
	int from,to;
	ll c,f;
	edge(int a,int b,ll m,ll n):from(a),to(b),c(m),f(n){}
};

struct dinic{
	int m,s,t;
	vector<edge>e;
	vector<int>g[maxm];
	bool vis[maxm];
	int d[maxm],cur[maxm];
	void init(int n){
		for(int i=0;i<n+5;i++)g[i].clear();
		e.clear();
	}
	void ini(){
		for(int i=0;i<e.size();i++){
			e[i].f=0;
		}
	}
	void add(int a,int b,ll v){
		e.push_back(edge(a,b,v,0));
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
			int u=q.front();
			q.pop();
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
	ll dfs(int x,ll a){
		if(x==t||a==0)return a;
		ll flow=0,f;
		for(int& i=cur[x];i<g[x].size();i++){
			edge& tmp=e[g[x][i]];
			if(d[x]+1==d[tmp.to]&&(f=dfs(tmp.to,min(a,tmp.c-tmp.f)))>0){
				tmp.f+=f;;
				e[g[x][i]^1].f-=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		if(!flow)d[x]=-1;
		return flow;
	}
	ll mf(int s,int t){
		this->s=s;
		this->t=t;
		ll flow=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,INF);
		}
		return flow;
	}
};

int main(){
	int n,m,s;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF&&n+m+s){
		int i;
		dinic d;
		d.init(n+10);
		for(i=1;i<=m;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			d.add(a,b,v);
			d.add(b,a,v);
		}
		ll ans=INF;
		for(i=1;i<=n;i++){
			if(i!=s){
				d.ini();
				ll tmp=d.mf(s,i);
				if(tmp<ans)ans=tmp;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
