#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=2e4+5;
const int maxm=5e4+5;

int head[maxn],point[maxm],nxt[maxm],size;
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn];
int fa[maxn];
int vis[maxn];
stack<int>S;
bool f;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	f=1;
	memset(vis,0,sizeof(vis));
	memset(fa,-1,sizeof(fa));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void dfs(int s,int pre){
	fa[s]=pre;
	stx[s]=low[s]=++t;
	S.push(s);
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!stx[j]){
			dfs(j,s);
			low[s]=min(low[s],low[j]);
		}
		else if(!scc[j]){
			if(stx[j]<stx[s]){
				int k=s;
				while(k!=j&&k!=-1){
					vis[k]++;
					k=fa[k];
				}
			}
			else f=0;
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
	for(int i=0;i<n;++i)if(!stx[i])dfs(i,-1);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		scanf("%d",&n);
		init();
		int a,b;
		while(scanf("%d%d",&a,&b)&&a+b){
			add(a,b);
		}
		setscc();
		for(int i=0;i<n;++i)if(vis[i]>1)f=0;
		if(scccnt>1||!f)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
