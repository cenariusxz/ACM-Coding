#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int maxm=150+5;
const int INF=0x3f3f3f3f;

int n,p,mach[105][15],l[105];

struct edge{
	int from,to,c,f;
	edge(int a,int b,int m,int n):from(a),to(b),c(m),f(n){}
};

struct dinic{
	int n,m,s,t;
	vector<edge>e;
	vector<int>g[maxm];
	bool vis[maxm];
	int d[maxm],cur[maxm];
	void init(int n){
		for(int i=0;i<n+5;i++)g[i].clear();
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
	while(scanf("%d%d",&p,&n)!=EOF){
		int i,j,k;
		dinic D;
		D.init(2*n+1);
		memset(mach,0,sizeof(mach));
		for(i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(j=1;j<=p;j++)scanf("%d",&mach[i+n][j]);
			for(j=1;j<=p;j++)scanf("%d",&mach[i][j]);
			D.add(i+n,i,l[i]);
		}
		for(i=1;i<=p;i++)mach[2*n+1][i]=1;
		for(i=0;i<=n;i++){
			for(j=n+1;j<=2*n+1;j++){
				bool f=1;
				for(k=1;k<=p;k++){
					if((mach[j][k]==0||mach[j][k]==1)&&mach[i][k]!=mach[j][k]){f=0;break;}
				}
				if(f)D.add(i,j,INF);
			}
		}
		int ans=D.mf(0,2*n+1);
		printf("%d ",ans);
		ans=0;
		for(i=1;i<D.e.size();i+=2){
			if(D.e[i].f&&D.e[i].from>n&&D.e[i].from!=2*n+1&&D.e[i].to<=n&&D.e[i].to!=0){
				ans++;
			}
		}
		printf("%d\n",ans);
		for(i=1;i<D.e.size();i+=2){
			if(D.e[i].f&&D.e[i].from>n&&D.e[i].from!=2*n+1&&D.e[i].to<=n&&D.e[i].to!=0){
				printf("%d %d %d\n",D.e[i].to,D.e[i].from-n,D.e[i].c-D.e[i].f);
			}
		}
	}
	return 0;
}
