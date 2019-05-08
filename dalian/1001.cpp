#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],point[maxm<<1],nxt[maxm<<1],size;
int vis[maxn];
int c[maxn];            //color，每个点的黑白属性，-1表示还没有标记，0/1表示黑白
bool f=0;                //判断是否出现奇环

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(c,-1,sizeof(c));
	memset(vis,0,sizeof(vis));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void dfs(int s,int x){
	if(f)return;
	c[s]=x;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(c[j]==-1)dfs(j,!x);
		else if(c[j]==x){
			f=1;
			return;
		}
	}
}


int main(){
	int n,m,x,y;
	int a,b;
	while(scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF){
		init();
		while(m--){
			scanf("%d%d",&a,&b);
			add(a,b);
			vis[a]=1;vis[b]=1;
		}
		for(int i=1;i<=x;++i){
			scanf("%d",&a);
			c[a]=0;
			vis[a]=1;
		}
		for(int i=1;i<=y;++i){
			scanf("%d",&a);
			c[a]=1;
			vis[a]=1;
		}
		f=0;
		for(int i=1;i<=n;++i){
			if(!vis[i])f=1;
		}
		if(f)printf("NO\n");
		else{
			for(int i=1;i<=n;++i){
				if(c[i]!=-1)dfs(i,c[i]);
			}
			for(int i=1;i<=n&&(!f);++i){
				if(c[i]==-1)dfs(i,1);
			}
			if(f)printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}
