#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=1005;
const int maxm=6005;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
int n,t,scccnt;
int id[maxn],stx[maxn],low[maxn],scc[maxn];
stack<int>S;

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
	memset(id,0,sizeof(head));
}

void add(int a,int b,int c=0){
	point[c][size[c]]=b;
	nxt[c][size[c]]=head[c][a];
	head[c][a]=size[c]++;
	if(c)id[b]++;
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
	t=0;
	scccnt=0;
	for(int i=1;i<=n;++i)if(!stx[i])dfs(i);
	for(int i=1;i<=n;++i){
		for(int j=head[0][i];~j;j=nxt[0][j]){
			int k=point[0][j];
			if(scc[i]!=scc[k]){
				add(scc[i],scc[k],1);
			}
		}
	}
}

bool topo(){
	queue<int>q;
	int cnt=0;
	for(int i=1;i<=scccnt;++i)if(!id[i])q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(!q.empty())return 0;
		cnt++;
		for(int i=head[1][u];~i;i=nxt[1][i]){
			int j=point[1][i];
			id[j]--;
			if(!id[j])q.push(j);
		}
	}
	if(cnt==scccnt)return 1;
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		scanf("%d%d",&n,&m);
		init();
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		setscc();
		if(topo())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
