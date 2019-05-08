#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=10005;
const int maxm=2e5+5;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn];
int vis[maxn],match[maxn];
stack<int>S;

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
}

void add(int a,int b,int c=0){
	point[c][size[c]]=b;
	nxt[c][size[c]]=head[c][a];
	head[c][a]=size[c]++;
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
				add(scc[i],scc[k]+scccnt,1);
			}
		}
	}
}

int dfs1(int k){
	for(int i=head[1][k];~i;i=nxt[1][i]){
		if(!vis[point[1][i]]){
			int p=point[1][i];
			vis[p]=1;
			if(match[p]==-1||dfs1(match[p])){
				match[p]=k;
				return 1;
			}
		}
	}
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
		int ans=0;
		memset(match,-1,sizeof(match));
		for(int i=1;i<=2*scccnt;++i){
			memset(vis,0,sizeof(vis));
			if(dfs1(i)==1)ans++;
		}
		printf("%d\n",scccnt-ans);
	}
	return 0;
}
