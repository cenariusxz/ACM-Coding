#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

const int maxn=505;
const int maxm=250005;
const int INF=0x3f3f3f3f;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2],val[2][maxm];
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn];
int dis[maxn];
stack<int>S;

int min(int a,int b){return a<b?a:b;}

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
}

void add(int a,int b,int v,int c=0){
	point[c][size[c]]=b;
	nxt[c][size[c]]=head[c][a];
	val[c][size[c]]=v;
	head[c][a]=size[c]++;
}

struct cmp{                    //将优先队列改为小根堆
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(int s,int t){            //传入出发点和到达点
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dis[u.second])continue;
		for(i=head[1][u.second];~i;i=nxt[1][i]){
			int j=point[1][i];
			if(dis[j]>u.first+val[1][i]){
				dis[j]=u.first+val[1][i];
				q.push(make_pair(dis[j],j));
			}
		}
	}
	if(dis[t]==INF)printf("Nao e possivel entregar a carta\n");
	else printf("%d\n",dis[t]);
}

void dfs(int s){
	stx[s]=low[s]=++t;
	S.push(s);
	for(int i=head[0][s];~i;i=nxt[0][i]){
		int j=point[0][i];
		if(!stx[j]){
			dfs(j);
			low[s]=min(low[s],low[j]);
		}
		else if(!scc[j]){
			low[s]=min(low[s],stx[j]);
		}
	}
	if(low[s]==stx[s]){
		scccnt++;
		while(1){
			int u=S.top();S.pop();
			scc[u]=scccnt;
			if(s==u)break;
		}
	}
}

void setscc(){
	memset(stx,0,sizeof(stx));
	memset(scc,0,sizeof(scc));
	t=scccnt=0;
	for(int i=1;i<=n;++i)if(!stx[i])dfs(i);
	for(int i=1;i<=n;++i){
		for(int j=head[0][i];~j;j=nxt[0][j]){
			int k=point[0][j];
			if(scc[i]!=scc[k]){
				add(scc[i],scc[k],val[0][j],1);
			}
		}
	}
}

int main(){
	int m;
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d",&m);
		init();
		while(m--){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		setscc();
		int k;
		scanf("%d",&k);
		while(k--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(scc[a]==scc[b])printf("0\n");
			else{
				dij(scc[a],scc[b]);
			}
		}
		printf("\n");
	}
	return 0;
}
