#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],point[maxm],nxt[maxm],size;
int match[maxn],vis[maxn];
int dep[maxn];

void init(){
	memset(dep,0,sizeof(dep));
	memset(head,-1,sizeof(head));
	size=0;
	memset(match,-1,sizeof(match));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

int dfs(int s){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j]){
			vis[j]=1;
			if(match[j]==-1||dfs(match[j])){
				match[j]=s;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,n+b);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			if(dfs(i)==1)ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
