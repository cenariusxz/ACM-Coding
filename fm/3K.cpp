#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=100;
const int maxm=1e4+5;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn];
int id[maxn],od[maxn];
stack<int>S;

int max(int a,int b){return a>b?a:b;}

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
	memset(id,0,sizeof(id));
	memset(od,0,sizeof(od));
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
				add(scc[i],scc[k],1);
				od[scc[i]]++;
				id[scc[k]]++;
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;++i){
		int b;
		while(scanf("%d",&b)&&b){
			add(i,b);
		}
	}
	setscc();
	int in=0,out=0;
	for(int i=1;i<=scccnt;++i){
		if(!id[i])in++;
		if(!od[i])out++;
	}
	printf("%d\n%d\n",in,scccnt==1?0:max(in,out));
	return 0;
}
