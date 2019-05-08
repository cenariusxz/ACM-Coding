#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxm=105;

int vis[maxm],topo[maxm],t;
int head[maxm],point[maxm*maxm],nxt[maxm*maxm],size;

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
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		memset(head,-1,sizeof(head));
		size=0;
		for(int i=1;i<=m;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		toposort(n);
		for(int i=1;i<=n;++i){
			printf("%d",topo[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
