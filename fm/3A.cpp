#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=2e4+5;
const int maxm=5e4+5;

int head[maxn],point[maxm],nxt[maxm],size;
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn],id[maxn],od[maxn],numi,numo;
stack<int>S;

int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void dfs(int s){
	stx[s]=low[s]=++t;
	S.push(s);
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
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
			int u=S.top();
			S.pop();
			scc[u]=scccnt;
			if(s==u)break;
		}
	}
}

void setscc(){
	memset(stx,0,sizeof(stx));
	memset(scc,0,sizeof(scc));
	memset(id,0,sizeof(id));
	memset(od,0,sizeof(od));
	numi=numo=t=scccnt=0;
	for(int i=1;i<=n;++i)if(!stx[i])dfs(i);
	if(scccnt!=1){
		for(int i=1;i<=n;++i){
			for(int j=head[i];~j;j=nxt[j]){
				int k=point[j];
				if(scc[i]!=scc[k]){
					id[scc[i]]++;
					od[scc[k]]++;
					if(id[scc[i]]==1)numi++;
					if(od[scc[k]]==1)numo++;
				}
			}
		}
		numi=scccnt-numi;
		numo=scccnt-numo;
	}
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
		printf("%d\n",max(numi,numo));
	}
	return 0;
}
		
