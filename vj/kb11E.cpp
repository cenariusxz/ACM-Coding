#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
const int maxm=6000;
const int INF=0x3f3f3f3f;

int num[55][55],sto[55][55],sum[55];

struct edge{
	int from,to,c,f,cost;
	edge(int a,int b,int m,int n,int p):from(a),to(b),c(m),f(n),cost(p){}
};

struct mumf{
	int m,s,t;
	vector<edge>e;
	vector<int>g[maxm];
	int a[maxm],dis[maxm],p[maxm];
	bool vis[maxm];

	void init(int n){
		for(int i=0;i<=n;i++)g[i].clear();
		e.clear();
	}

	void add(int a,int b,int c,int v){
		e.push_back(edge(a,b,c,0,v));
		e.push_back(edge(b,a,0,0,-v));
		m=e.size();
		g[a].push_back(m-2);
		g[b].push_back(m-1);
	}

	bool spfa(int& flow,int& cost){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(s);
		dis[s]=0;
		vis[s]=1;
		p[s]=0;
		a[s]=INF;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=0;i<g[u].size();i++){
				edge tmp=e[g[u][i]];
				if(dis[tmp.to]>dis[u]+tmp.cost&&tmp.c>tmp.f){
					dis[tmp.to]=dis[u]+tmp.cost;
					p[tmp.to]=g[u][i];
					a[tmp.to]=min(a[u],tmp.c-tmp.f);
					if(!vis[tmp.to]){
						q.push(tmp.to);
						vis[tmp.to]=1;
					}
				}
			}
		}
		if(dis[t]==INF)return 0;
		flow+=a[t];
		cost+=dis[t]*a[t];
		int u=t;
		while(u!=s){
			e[p[u]].f+=a[t];
			e[p[u]^1].f-=a[t];
			u=e[p[u]].from;
		}
		return 1;
	}

	int mf(int s,int t){
		this->s=s;
		this->t=t;
		int flow=0,cost=0;
		while(spfa(flow,cost));
		return cost;
	}

};

int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF&&n!=0||m!=0||k!=0){
		memset(num,0,sizeof(num));
		memset(sto,0,sizeof(sto));
		memset(sum,0,sizeof(sum));
		int i,j,l;
		bool f=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=k;j++){
				scanf("%d",&num[i][j]);
				sum[j]+=num[i][j];
			}
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=k;j++){
				scanf("%d",&sto[i][j]);
				sum[j]-=sto[i][j];
			}
		}
		int ans=0;
		for(i=1;i<=k;i++)if(sum[i]>0)f=0;
		for(i=1;i<=k;i++){
			mumf M;
			M.init(n+10);
			if(f)for(j=1;j<=m;j++){
				M.add(0,j,sto[j][i],0);
			}
			for(j=1;j<=n;j++){
				if(f)M.add(m+j,m+n+1,num[j][i],0);
				for(l=1;l<=m;l++){
					int p;
					scanf("%d",&p);
					if(f){
						M.add(l,m+j,INF,p);
					}
				}
			}

			if(f)ans+=M.mf(0,m+n+1);
		}
		if(f)printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}	
