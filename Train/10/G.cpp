#include<stdio.h>        //大概这么多头文件昂
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=200;    //最大点数
const int INF=0x3f3f3f3f;

struct edge{        //边：起点、终点、容量、流量、单位费用
	int from,to,c,f,cost;
	edge(int a,int b,int m,int n,int p):from(a),to(b),c(m),f(n),cost(p){}
};

int aabs(int a){
	return a>=0?a:-a;
}

struct MCMF{
	int m,s,t;
	vector<edge>e;
	vector<int>g[maxm];
	int dis[maxm],a[maxm],p[maxm];
	bool vis[maxm];

	void init(int n){        //初始化函数
		for(int i=0;i<=n;i++)g[i].clear();
		e.clear();
	}

	void add(int a,int b,int c,int v){    //加边函数
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
		vis[s]=1;
		dis[s]=0;
		p[s]=0;
		a[s]=INF;
		while(!q.empty()){
			int u=q.front();q.pop();
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

	int MF(int s,int t){
		this->s=s;this->t=t;
		int flow=0,cost=0;
		while(spfa(flow,cost));
		return cost;
	}

};

int deg[maxm];

void init(){
	memset(deg,0,sizeof(deg));
}

int main(){
	int T;
	scanf("%d",&T);

	for(int q=1;q<=T;++q){
		int n,m,s,t;
		scanf("%d%d%d%d",&n,&m,&s,&t);
		init();
		deg[s]=-1;
		deg[t]=1;
		MCMF M;
		M.init(n+2);
		int sum=0;
		while(m--){
			int i,j,a,b;
			scanf("%d%d%d%d",&i,&j,&a,&b);
			if(a>=b){
				M.add(i,j,1,a-b);
				sum+=b;
			}
			else{
				M.add(j,i,1,b-a);
				deg[i]++;
				deg[j]--;
				sum+=a;
			}
		}
		for(int i=1;i<=n;++i){
			if(deg[i]<0){
				M.add(0,i,-deg[i],0);
			}
			if(deg[i]>0){
				M.add(i,n+1,deg[i],0);
			}
		}
		int ss=M.MF(0,n+1);
		bool f=1;
		for(int i=0;i<M.g[0].size();++i){
			edge u=M.e[M.g[0][i]];
		//	printf("%d %d %d %d %d\n",u.from,u.to,u.c,u.f,u.cost);
			if(u.f<u.c){
				f=0;
				break;
			}
		}
		printf("Case %d: ",q);
		if(f)printf("%d\n",sum+ss);
		else printf("impossible\n");
	}
	return 0;
}
