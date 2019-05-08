#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<bitset>
using namespace std;
const int maxn=2050;

char s[2050][2050];
int G[2][maxn][maxn];
int head[2][maxn],point[2][maxn*maxn],nxt[2][maxn*maxn],size[2];
bitset<maxn>g[2][maxn];

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
}

void add(int a,int b,int x){
	point[x][size[x]]=b;
	nxt[x][size[x]]=head[x][a];
	head[x][a]=size[x]++;
}

int n;

bool check(int x){
	for(int i=1;i<=n;++i){
		for(int k=head[x][i];~k;k=nxt[x][k]){
			int j=point[x][k];
			if((g[x][j]&g[x][i])!=g[x][i])return 0;
		}
	}
	return 1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		memset(G,0,sizeof(G));
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]+1);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				g[0][i][j]=g[1][i][j]=0;
				if(s[i][j]=='P'){
					G[0][i][j]=1;
					g[0][i][j]=1;
					add(j,i,0);
				}
				else if(s[i][j]=='Q'){
					G[1][i][j]=1;
					g[1][i][j]=1;
					add(j,i,1);
				}
			}
		}
		if(!check(0))printf("N\n");
		else if(!check(1))printf("N\n");
		else printf("T\n");

	}
	return 0;
}
