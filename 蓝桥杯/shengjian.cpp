#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[10];
int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};
int vis[10][50];
int s,ans;
int n;

void dfs(int x,int y,int c){
	vis[x][y]=1;
	++c;
	if(c==s){
		ans++;
		vis[x][y]=0;
		return;
	}
	for(int i=0;i<4;++i){
		int dx=x+xx[i];
		int dy=y+yy[i];
		if(dx>=1&&dx<=n&&dy>=1&&dy<=a[dx]&&!vis[dx][dy]){
			dfs(dx,dy,c);
		}
	}
	vis[x][y]=0;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		s=0;ans=0;
		for(int i=1;i<=n;++i)s+=a[i];
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=a[i];++j){
				dfs(i,j,0);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
