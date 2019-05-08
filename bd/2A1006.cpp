#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],point[maxm],nxt[maxm],size;
int vis[maxm],topo[maxm],t;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

bool dfs(int s){
	vis[s]=-1;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(vis[j]==-1)return 0;
		if(!vis[j]&&!dfs(j))return 0;
	}
	vis[s]=1;
	topo[t--]=s;
	return 1;
}

bool toposort(int n){
	t=n;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			if(!dfs(i))return 0;
		}
	}
	return 1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		toposort(n);
		ll minn=topo[1];
		ll ans=0;
		for(int i=1;i<=n;++i){
			if(topo[i]<minn)minn=topo[i];
			ans+=minn;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
