#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=2e4+5;
const int maxm=4e5+5;
const int maxl=20;		//总点数的log范围，一般会开稍大一点

int fa[maxn],dep[maxn],vis[maxn];
int head[maxn],point[maxm],nxt[maxm],size;
// 0 是树边，1 是图边
int dp[maxn];
int n,ans;
vector<int> v[maxn];

void init(){
	size=0;
	memset(head,-1,sizeof(head));
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		fa[i]=i;
		v[i].clear();
	}
	ans=0x3f3f3f3f;
}

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void Tarjan(int s,int pre){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==pre)continue;
		Tarjan(j,s);
		int x=find(j),y=find(s);
		if(x!=y)fa[x]=y;
	}
	vis[s]=1;
	for(int i=0;i<v[s].size();++i){
		int j=v[s][i];
		if(vis[j]){
			int lca=find(j);
			dp[s]++;
			dp[j]++;
			dp[lca]-=2;
		}
	}
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void DFS1(int s,int pre){
	for(int i=head[s];~i;i=nxt[i]){
		if(point[i]==pre)continue;
		DFS1(point[i],s);
		dp[s]+=dp[point[i]];
	}
	if(s!=1&&dp[s]<ans)ans=dp[s];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int m;
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=m-n+1;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		Tarjan(1,-1);
		DFS1(1,-1);
		printf("Case #%d: %d\n",q,ans);
	}
	return 0;
}
