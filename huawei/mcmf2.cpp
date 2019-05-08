#include<stdio.h>        //大概这么多头文件昂
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int maxn=505;    //最大点数
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

struct edge{
	int from,nxt,point,volume,flow,cost;
	edge(int fr,int nx,int po,int vo,int fl,int co):
		from(fr),nxt(nx),point(po),volume(vo),flow(fl),cost(co){}
	edge(){}
};

struct save_edge{
	int a,b,c,v;
	bool operator < (const save_edge x)const{
		return v<x.v;
	}
}se[200000];

struct save_t{
	int id,a,c;
}st[505];

inline int aabs(int a){
	return a>=0?a:-a;
}

int m,s,t;
int head[maxn],size;
edge e[maxm];
//int head1[maxn],size1;
//edge e2[maxm]
int dis[maxm],a[maxm],p[maxm];
bool vis[maxm];
int Min=0;

inline void init(){        //初始化函数
	size=0;
	memset(head,-1,sizeof(head));
}

inline void add(int a,int b,int c,int v){    //加边函数
	e[size]=edge(a,head[a],b,c,0,v);
	head[a]=size++;
	
	e[size]=edge(b,head[b],a,0,0,-v);
	head[b]=size++;
}

inline bool spfa(int& Flow,int& Cost){
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
		for(int i=head[u];~i;i=e[i].nxt){
			int pi=e[i].point;
			if(dis[pi]>dis[u]+e[i].cost&&e[i].volume>e[i].flow){
				dis[pi]=dis[u]+e[i].cost;
				p[pi]=i;
				a[pi]=min(a[u],e[i].volume-e[i].flow);
				if(!vis[pi]){
					q.push(pi);
					vis[pi]=1;
				}
			}
		}
	}
	if(dis[t]==INF)return 0;
	Flow+=a[t];
	Cost+=dis[t]*a[t];
	int u=t;
	while(u!=s){
		e[p[u]].flow+=a[t];
		e[p[u]^1].flow-=a[t];
		u=e[p[u]].from;
	}
	return 1;
}

int count1=0;
int N,M,Q,S;

inline pair<int,int> MF(int s1,int t1){
	s=s1;t=t1;
	int Flow=0,Cost=0;
	while(spfa(Flow,Cost)){
		if(Cost+count1*S>Min)return make_pair(0,0);
	}
	return make_pair(Flow,Cost);
}

int v1[maxm];
int sum=0;

void dfs(int num,int p){
	if(num==0){
		init();
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
			if(p.second+count1*S<Min){
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
	dfs(num,p+1);
	v1[p]=1;
	dfs(num-1,p+1);
	v1[p]=0;
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
	for(int i=4;i<=4;++i){
		printf("i: %d\n",i);
		count1=i;
		memset(v1,0,sizeof(v1));
		dfs(i,1);
//		if(Min!=INF)printf("%d %d",i,Min);
	}
	printf("%d\n",clock()-t1);
	return 0;
}
