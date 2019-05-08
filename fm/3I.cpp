#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=5005;
const int maxm=30005;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
int n,t,scccnt,maxx;
int stx[maxn],low[maxn],scc[maxn];
int dp[maxn],id[maxn],vis[maxn];
int fa[maxn];
stack<int>S;

int max(int a,int b){return a>b?a:b;}

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
	memset(dp,0,sizeof(dp));
	memset(id,0,sizeof(id));
	memset(fa,-1,sizeof(fa));
	maxx=0;
}

void add(int a,int b,int c=0){
	if(c){
		for(int i=head[1][a];~i;i=nxt[1][i])if(point[1][i]==b)return;
	}
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
			dp[scccnt]++;
			if(s==u)break;
		}
	}
}

void setscc(){
	memset(stx,0,sizeof(stx));
	memset(scc,0,sizeof(scc));
	t=scccnt=0;
	for(int i=0;i<n;++i)if(!stx[i])dfs(i);
	for(int i=0;i<n;++i){
		for(int j=head[0][i];~j;j=nxt[0][j]){
			int k=point[0][j];
			if(scc[i]!=scc[k]){
				add(scc[i],scc[k],1);
				id[scc[k]]++;
			}
		}
	}
}

int Dp(int s){
	int ans=0;
	vis[s]=1;
	for(int i=head[1][s];~i;i=nxt[1][i]){
		if(!vis[point[1][i]])ans+=Dp(point[1][i]);
	}
	return ans+dp[s];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int m;
		scanf("%d%d",&n,&m);
		init();
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(b,a);
		}
		setscc();
		for(int i=1;i<=scccnt;++i)if(!id[i]){
			memset(vis,0,sizeof(vis));
			dp[i]=Dp(i)-1;
			if(dp[i]>maxx)maxx=dp[i];
		}
		int ans=0;
		printf("Case %d: %d\n",q,maxx);
		int cnt=0;
		for(int i=0;i<n;++i){
			if(!id[scc[i]]&&dp[scc[i]]==maxx){
				if(cnt++)printf(" ");
				printf("%d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
