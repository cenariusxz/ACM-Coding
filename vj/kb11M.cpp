#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=1050;
const int INF=0x3f3f3f3f;

struct edge{
	int from,to,c,f;
	edge(int a,int b,int m,int n):from(a),to(b),c(m),f(n){}
};

struct dinic{
	int s,t,m;
	vector<edge>e;
	vector<int>g[maxm];
	bool vis[maxm];
	int cur[maxm],d[maxm];

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
			if(d[tmp.to]==d[x]+1&&(f=dfs(tmp.to,min(a,tmp.c-tmp.f)))>0){
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

int num[1050];

int main(){
	int n,m,i,j;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(num,0,sizeof(num));
		dinic d;
		d.init(m+(1<<m)+5);
		int tmp;
		for(i=1;i<=n;i++){
			tmp=0;
			for(j=1;j<=m;j++){
				int a=0;/*
				char c=getchar();
				while(c>'9'||c<'0')c=getchar();
				a=c-'0';*/
				scanf("%d",&a);
				tmp=tmp*2+a;
			}
			num[tmp]++;
		}
		for(i=1;i<=(1<<m)-1;i++){
			if(num[i]){
				d.add(0,i,num[i]);
				tmp=i;
				for(j=m;j>=1;j--){
					if(tmp&1)d.add(i,(1<<m)+j,INF);
					tmp>>=1;
				}
			}
		}
		for(j=1;j<=m;j++){
			int a=0;/*
			char c=getchar();
			while(c>'9'||c<'0')c=getchar();
			while(c>='0'&&c<='9'){
				a=a*10+c-'0';
				c=getchar();
			}*/
			scanf("%d",&a);
			d.add((1<<m)+j,m+(1<<m)+1,a);
		}
		if(n==d.mf(0,m+(1<<m)+1))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
