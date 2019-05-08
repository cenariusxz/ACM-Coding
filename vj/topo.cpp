#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],point[maxm],nxt[maxm],size;
int ma[maxm][maxm],id[maxm],n,vis[maxm],v[maxm];
int ans[maxm];

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
}

void dfs(int s,int t){
	ans[t]=s;
	v[s]=1;
	if(t==n){
		for(int i=1;i<=n;++i){
			printf("%d",ans[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
		v[s]=0;
		return;
	}
	int que[maxn],cnt=0;
	for(int i=1;i<=n;++i){
		if(ma[s][i])id[i]--;
		if(vis[i]&&!id[i]&&!v[i])que[++cnt]=i;
	}
	for(int i=1;i<=cnt;++i)dfs(que[i],t+1);
	for(int i=1;i<=n;++i)if(ma[s][i])id[i]++;
	v[s]=0;
}

for(int i=1;i<=n;++i){
	if(vis[i]&&!id[i])dfs(i,1);
}
