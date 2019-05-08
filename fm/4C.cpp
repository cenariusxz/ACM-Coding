#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=8e4+5;
const int maxm=maxn*2;

int fa[maxn],dep[maxn];
int head[maxn],point[maxm],nxt[maxm],size;
int n,num[maxn],que[maxn],cnt;

void init(){
	size=0;
	memset(head,-1,sizeof(head));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void Dfs(int s,int pre){
	fa[s]=pre;
	dep[s]=dep[pre]+1;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==pre)continue;
		Dfs(j,s);
	}
}

void Pre(){
	dep[1]=0;
	Dfs(1,-1);
}

void Lca(int u,int v){
	cnt=0;
	if(dep[u]>dep[v])swap(u,v);
	while(dep[u]<dep[v]){
		que[++cnt]=num[v];
		v=fa[v];
	}
	while(u!=v){
		que[++cnt]=num[u];
		u=fa[u];
		que[++cnt]=num[v];
		v=fa[v];
	}
	que[++cnt]=num[u];
}

int main(){
	int m;
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;++i)scanf("%d",&num[i]);
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	Pre();
	while(m--){
		int f,a,b;
		scanf("%d%d%d",&f,&a,&b);
		if(f){
			Lca(a,b);
			if(cnt<f)printf("invalid request!\n");
			else{
				sort(que+1,que+cnt+1);
				printf("%d\n",que[cnt-f+1]);
			}
		}
		else num[a]=b;
	}
}
