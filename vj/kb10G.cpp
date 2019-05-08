#include<stdio.h>
#include<string.h>

const int maxn=4e5+5;
const int maxm=2e6+5;

int head[maxn],point[maxm],nxt[maxm],size;
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

int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};
int id[605][605];
char s[605][605];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		int cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				id[i][j]=++cnt;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if((i+j)%2&&s[i][j]=='#'){
					for(int k=0;k<4;++k){
						int x=i+xx[k],y=j+yy[k];
						if(x>=1&&x<=n&&y>=1&&y<=n&&s[x][y]=='#'){
							add(id[i][j],id[x][y]);
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if((i+j)%2&&s[i][j]=='#'){
					memset(vis,0,sizeof(vis));
					if(dfs(id[i][j])==1)ans++;
				}
			}
		}
		printf("Case %d: %d\n",q,ans);
	}
	return 0;
}
