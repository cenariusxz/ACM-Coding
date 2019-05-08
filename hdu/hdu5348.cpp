#include<stdio.h>
#include<string.h>

const int maxm=6e5+5;
const int maxn=1e5+5;

int head[maxn],point[maxm],nxt[maxm],size,val[maxm];
int head2[maxn],point2[maxm],nxt2[maxm],size2,val2[maxm],to[maxm];
int num[maxn];
bool vis[maxn];
bool f;
int p;

inline void add(int a,int b){
	point[size]=b;
	val[size]=-1;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	val[size]=-1;
	nxt[size]=head[b];
	head[b]=size++;
}

inline void add2(int a,int b){
	point2[size2]=b;
	val2[size2]=-1;
	nxt2[size2]=head2[a];
	head2[a]=size2++;
	point2[size2]=a;
	val2[size2]=-1;
	nxt2[size2]=head2[b];
	head2[b]=size2++;
}

inline int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void dfs(int s){
	if(vis[s]){
		f=1;
		p=s;
		return;
	}
	vis[s]=1;
	for(int i=head[s];~i;i=nxt[i]){
		if(val[i]==-1){
			int j=point[i];
			val[i]=val[i^1]=2;
			dfs(j);
			if(f){
				val[i]=0;
				val[i^1]=1;
				vis[s]=0;
				if(s!=p)return;
				else f=0;
			}
		}
	}
	vis[s]=0;
}

void dfs2(int s){
	vis[s]=1;
	for(int i=head[s];~i;i=nxt[i]){
		if(val[i]==2){
			int j=point[i];
			if(num[s]==0||num[s]==-1){
				num[s]++;
				num[j]--;
				val[i]=1;
				val[i^1]=0;
				dfs2(j);
			}
			else if(num[s]==1){
				num[s]--;
				num[j]++;
				val[i]=0;
				val[i^1]=1;
				dfs2(j);
			}
		}
	}
}

int main(){
//	int T=read();
	int T;
	scanf("%d",&T);
	while(T--){
//		int n=read();
//		int m=read();
		int n,m;
		scanf("%d%d",&n,&m);
		int i;
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		size=0;
		memset(num,0,sizeof(num));
		for(i=1;i<=m;i++){
//			int a=read();
//			int b=read();
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		for(i=1;i<=n;++i){
			f=0;
			dfs(i);
		}
		for(i=1;i<=n;++i){
			if(!vis[i])dfs2(i);
		}
		for(i=0;i<size;i+=2)printf("%d\n",val[i]);
	}
	return 0;
}
