#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],point[maxm<<1],nxt[maxm<<1],size;
int match[maxn],vis[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(match,-1,sizeof(match));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
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
		init();
		int n,p;
		scanf("%d%d",&p,&n);
		for(int i=1;i<=p;++i){
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;++j){
				int a;
				scanf("%d",&a);
				add(i,p+a);
			}
		}
		int ans=0;
		for(int i=1;i<=p;i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i)==1)ans++;
		}
		if(ans==p)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
