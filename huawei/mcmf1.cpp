#include<stdio.h>        //大概这么多头文件昂
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int maxm=505;    //最大点数
const int INF=0x3f3f3f3f;

struct edge{        //边：起点、终点、容量、流量、单位费用
	int from,to,c,f,cost;
	edge(int a,int b,int m,int n,int p):from(a),to(b),c(m),f(n),cost(p){}
};

struct save_edge{
	int a,b,c,v;
	bool operator < (const save_edge x)const{
		return v>x.v;
	}
}se[200000];

struct save_t{
	int id,a,c;
}st[505];

inline int aabs(int a){
	return a>=0?a:-a;
}

int m,s,t;
vector<edge>e;
vector<int>g[maxm];
int dis[maxm],a[maxm],p[maxm];
bool vis[maxm];
int Min=0;

inline void init(int n){        //初始化函数
	for(int i=0;i<=n;i++)g[i].clear();
	e.clear();
}

inline void add(int a,int b,int c,int v){    //加边函数
	e.push_back(edge(a,b,c,0,v));
	e.push_back(edge(b,a,0,0,-v));
	m=e.size();
	g[a].push_back(m-2);
	g[b].push_back(m-1);
}

inline bool spfa(int& flow,int& cost){
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

int count1=0;
int N,M,Q,S;

inline pair<int,int> MF(int s1,int t1){
	s=s1;t=t1;
	int flow=0,cost=0;
	while(spfa(flow,cost)){
//		if(cost+count1*S>Min)return make_pair(0,0);
		if(cost+count1*S>2026)return make_pair(0,0);
	}
	return make_pair(flow,cost);
}

int v1[maxm];
int sum=0;

void dfs(int num,int p){
	if(num==0){
		init(N+5);
		for(int i=1;i<=N;++i){
			if(v1[i]){
				add(0,i,INF,0);
			}
		}
		for(int i=1;i<=M;++i){
			add(se[i].a,se[i].b,se[i].c,se[i].v);
			add(se[i].b,se[i].a,se[i].c,se[i].v);
		}
		for(int i=1;i<=Q;++i){
			add(st[i].a,N+1,st[i].c,0);
		}
		pair<int,int> p=MF(0,N+1);
		if(p.first==sum){
//			if(p.second+count1*S<Min){
			if(p.second+count1*S<=2026){
				Min=p.second+count1*S;
				for(int i=1;i<=N;++i){
					if(v1[i])printf("%d ",i);
				}
				printf("\n");
				printf("%d\n",Min);

			}
		}
		return;
	}
	if(p==N+1)return;
	v1[p]=1;
	dfs(num-1,p+1);
	v1[p]=0;
	dfs(num,p+1);
}

int main(){
	scanf("%d%d%d%d",&N,&M,&Q,&S);
	for(int i=1;i<=M;++i){
		scanf("%d%d%d%d",&se[i].a,&se[i].b,&se[i].c,&se[i].v);
	}
	sort(se+1,se+M+1);
	for(int i=1;i<=Q;++i){
		scanf("%d%d%d",&st[i].id,&st[i].a,&st[i].c);
		sum+=st[i].c;
	}
	Min=INF;

	int t1=clock();
	for(int i=6;i<=6;++i){
		printf("i: %d\n",i);
		count1=i;
		memset(v1,0,sizeof(v1));
		dfs(i,1);
//		if(Min!=INF)printf("%d %d",i,Min);
	}
	printf("%d\n",clock()-t1);
	return 0;
}
