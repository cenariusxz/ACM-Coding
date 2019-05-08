#include<stdio.h>
#include<string.h>

const int maxn=205;
const int maxm=1e5+5;

int head[maxn],point[maxm],nxt[maxm],size;
int match[maxn],vis[maxn];
int M[105][105];
int r[105],c[105];

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
	int n;
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				scanf("%d",&M[i][j]);
				if(M[i][j]==1)add(i,n+j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			if(dfs(i)==1)ans++;
		}
		if(ans!=n)printf("-1\n");
		else{
			for(int i=1;i<=n;++i){
				int p=match[i+n];
				r[p]=i;
				c[i]=p;
			}
			printf("%d\n",n);
			for(int i=1;i<=n;++i){
				if(c[i]==i)printf("R %d %d\n",i,i);
				else{
					printf("R %d %d\n",i,c[i]);
					int rr=r[i],cc=c[i];
					c[i]=r[i]=i;
					r[cc]=rr;c[rr]=cc;
				}
			}
		}
	}
	return 0;
}
