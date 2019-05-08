#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
const int maxm=100000+10;
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
		for(int i=0;i<n;i++)g[i].clear();
		e.clear();
	}

	void add(int a,int b,int v){
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
			int u=q.front();q.pop();
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
			if(d[x]+1==d[tmp.to]&&(f=dfs(tmp.to,min(a,tmp.c-tmp.f)))>0){
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
	int n,m,k,i,j,cnt;
	string a,b;
	dinic D;
	D.init(maxm);
	map<string,int>M1,M2;
	M1.clear();
	M2.clear();
	scanf("%d",&n);
	cnt=2*n;
	for(i=1;i<=n;i++){
		cin>>a;
		M1[a]=i;
		M2[a]=i+n;
		D.add(0,i,1);
		D.add(i,i+n,INF);
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		cin>>a>>b;
		M2[a]=++cnt;
		if(!M2[b])M2[b]=++cnt;
		D.add(M2[b],M2[a],INF);
		D.add(M2[a],maxm-5,1);
	}
	
	scanf("%d",&k);
	for(i=1;i<=k;i++){
		cin>>a>>b;
		if(!M2[b])M2[b]=++cnt;
		if(!M2[a])M2[a]=++cnt;
		j=M2[b];
		D.add(j,M2[a],INF);
		if(M1[b])D.add(M1[b],M2[a],INF);
	}
	printf("%d\n",m-D.mf(0,maxm-5));

	return 0;
}
