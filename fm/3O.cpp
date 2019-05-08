#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=3e4+5;
const int maxm=2e5+5;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn],num[maxn],id[maxn],v[maxn];
int dp[maxn];
stack<int>S;

int max(int a,int b){return a>b?a:b;}

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
	memset(num,0,sizeof(num));
	memset(id,0,sizeof(id));
	memset(dp,-1,sizeof(dp));
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
			num[scccnt]+=v[u]>0?v[u]:0;
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
				id[scc[k]]++;
			}
		}
	}
}

int dfs1(int s){
	if(~dp[s])return dp[s];
	int maxx=0;
	for(int i=head[1][s];~i;i=nxt[1][i]){
		int j=point[1][i];
		maxx=max(maxx,dfs1(j));
	}
	dp[s]=maxx+num[s];
	return dp[s];
}

int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i=1;i<=n;++i)scanf("%d",&v[i]);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			a++;
			b++;
			add(a,b);
		}
		setscc();
		int ans=0;
		for(int i=1;i<=scccnt;++i){
			if(!id[i])ans=max(ans,dfs1(i));
		}
		printf("%d\n",ans);
	}
	return 0;
}
