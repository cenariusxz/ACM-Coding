#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],point[maxm],nxt[maxm],size;
int match[maxn],vis[maxn];
int get[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(match,-1,sizeof(match));
	memset(get,-1,sizeof(get));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

int del;

int dfs(int s,bool F){
	for(int i=head[s];~i;i=nxt[i]){
		if(!F&&i==del)continue;
		int j=point[i];
		if(!vis[j]){
			vis[j]=1;
			if(match[j]==-1||dfs(match[j],F)){
				if(F){
					match[j]=s;
					get[s]=i;
				}
				return 1;
			}
		}
	}
	return 0;
}


int main(){
	int T=0;
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		++T;
		init();
		while(k--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,n+b);
		}
		int ans1=0;
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			if(dfs(i,1))ans1++;
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(get[i]!=-1){
				del=get[i];
				match[point[del]]=-1;
				get[i]=-1;
				memset(vis,0,sizeof(vis));
				if(!dfs(i,0))ans++;
				get[i]=del;
				match[point[del]]=i;
			}
		}
		printf("Board %d have %d important blanks for %d chessmen.\n",T,ans,ans1);
	}
	return 0;
}
