#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=1005;
const int maxm=50005;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn],num[maxn],dp[maxn];
stack<int>S;

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
	memset(dp,0,sizeof(dp));
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
			num[scccnt]++;
			if(s==u)break;
		}
	}
}

void setscc(){
	memset(stx,0,sizeof(stx));
	memset(scc,0,sizeof(scc));
	memset(num,0,sizeof(num));
	t=scccnt=0;
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

void dfs1(int s){
	if(dp[s])return;
	dp[s]=num[s];
	for(int i=head[1][s];~i;i=nxt[1][i]){
		int j=point[1][i];
		dfs(j);
		if(num[s]+dp[j]>dp[s])dp[s]=num[s]+dp[j];
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
		int ans=0;
		for(int i=1;i<=scccnt;++i){
			dfs1(i);
			if(ans<dp[i])ans=dp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
