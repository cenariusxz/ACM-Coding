#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=5e4+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int head[maxn],point[maxm],nxt[maxm],size,val[maxm];
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn],vis[maxn];
int from[maxm],to[maxm],cost[maxm],cntm;
int pre[maxn],id[maxn],in[maxn];
stack<int>S;

void init(){
	memset(head,-1,sizeof(head));
	size=cntm=0;
	memset(vis,0,sizeof(vis));
}

void add_mdst(int a,int b,int v){
	from[cntm]=a;
	to[cntm]=b;
	cost[cntm++]=v;
}

ll mdst(int s,int n){
	ll ans=0;
	int u,v;
	while(1){
		memset(in,0x3f,sizeof(in));
		for(int i=0;i<cntm;++i){
			if(from[i]!=to[i]&&cost[i]<in[to[i]]){
				pre[to[i]]=from[i];
				in[to[i]]=cost[i];
			}
		}
		for(int i=1;i<=n;++i){
			if(i!=s&&in[i]==INF){
				return -1;
			}
		}
		int cnt=0;
		memset(id,-1,sizeof(id));
		memset(vis,-1,sizeof(vis));
		in[s]=0;
		for(int i=1;i<=n;++i){
			ans+=in[i];
			v=i;
			while(vis[v]!=i&&id[v]==-1&&v!=s){
				vis[v]=i;
				v=pre[v];
			}
			if(v!=s&&id[v]==-1){
				++cnt;
				for(u=pre[v];u!=v;u=pre[u])id[u]=cnt;
				id[v]=cnt;
			}
		}
		if(!cnt)break;
		for(int i=1;i<=n;++i){
			if(id[i]==-1)id[i]=++cnt;
		}
		for(int i=0;i<cntm;){
			v=to[i];
			from[i]=id[from[i]];
			to[i]=id[to[i]];
			if(from[i]!=to[i])cost[i++]-=in[v];
			else{
				--cntm;
				cost[i]=cost[cntm];
				to[i]=to[cntm];
				from[i]=from[cntm];
			}
		}
		n=cnt;
		s=id[s];
	}
	return ans;
}

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
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
		for(int j=head[i];~j;j=nxt[j]){
			int k=point[j];
			if(scc[i]!=scc[k]){
				add_mdst(scc[i],scc[k],val[j]);
			}
		}
	}
}

int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		while(m--){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a+1,b+1,v);
		}
		setscc();
		ll ans=0;
		int pre=scc[1];
		printf("%lld\n",mdst(pre,scccnt));
	}
	return 0;
}
