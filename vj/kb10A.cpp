#include<stdio.h>
#include<string.h>

const int maxn=1000;
const int maxm=10000;

int head[maxn],point[maxm<<1],nxt[maxm<<1],size;
int match[maxn],vis[maxn];
char s[5][5];
int row[5][5],col[5][5];

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
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		int cnt=0,r,c;
		for(int i=1;i<=n;++i){
			cnt++;
			for(int j=1;j<=n;++j){
				if(s[i][j]=='X')cnt++;
				else{
					row[i][j]=cnt;
				}
			}
		}
		r=cnt;
		for(int i=1;i<=n;++i){
			cnt++;
			for(int j=1;j<=n;++j){
				if(s[j][i]=='X')cnt++;
				else col[j][i]=cnt;
			}
		}
		init();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(s[i][j]!='X')add(row[i][j],col[i][j]);
			}
		}
		int ans=0;
		for(int i=1;i<=r;++i){
			memset(vis,0,sizeof(vis));
			if(dfs(i)==1)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
