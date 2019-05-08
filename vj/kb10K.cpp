#include<stdio.h>
#include<string.h>

const int maxn=1e3+5;
const int maxm=1e6+5;

int head[maxn],point[maxm],nxt[maxm],size;
int match[maxn],vis[maxn];
int g[505][505];


void init(){
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
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0)break;
		init();
		memset(g,0,sizeof(g));
		for(int i=1;i<=m;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			g[a][b]=1;
		}
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(g[i][k]&&g[k][j])g[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j&&g[i][j])add(i,n+j);
			}
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
