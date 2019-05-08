#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],point[maxm<<1],nxt[maxm<<1],size;
int c[maxn];            //color，每个点的黑白属性，-1表示还没有标记，0/1表示黑白
int match[maxn],vis[maxn];
int num[2];                //在一次DFS中的黑白点个数
bool f=0;                //判断是否出现奇环

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(c,-1,sizeof(c));
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

void dfs(int s,int x){
	if(f)return;
	c[s]=x;
	num[x]++;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(c[j]==-1)dfs(j,!x);
		else if(c[j]==x){
			f=1;
			return;
		}
	}
}

int Dfs(int s){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j]){
			vis[j]=1;
			if(match[j]==-1||Dfs(match[j])){
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
		init();
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		f=0;
		for(int i=1;i<=n&&(!f);i++){
			if(c[i]==-1){
				num[0]=num[1]=0;
				dfs(i,1);
			}
		}
		if(f)printf("No\n");
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(c[i]){
					memset(vis,0,sizeof(vis));
					if(Dfs(i)==1)ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
