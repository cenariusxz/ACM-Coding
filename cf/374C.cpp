#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct point{
	int x,y;
}p[1005*1005];

int vis[1005][1005];
int vis2[1005][1005];
int n,m;
bool f=1;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char s[1005][1005];

int dfs(int x,int y){
	if(!f)return 1;
	int i,j;
	if(vis[x][y]!=-1)return vis[x][y];
	if(s[x][y]=='D')vis2[x][y]=-1;
	bool ff=1;
	for(i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
			if((s[x][y]=='D'&&s[xx][yy]=='I')||
				(s[x][y]=='I'&&s[xx][yy]=='M')||
				(s[x][y]=='M'&&s[xx][yy]=='A')){
				ff=0;
				vis[x][y]=max(vis[x][y],dfs(xx,yy));
			}
			else if(s[x][y]=='A'&&s[xx][yy]=='D'){
				ff=0;
				if(vis2[xx][yy]==-1){f=0;return 1;}
				vis[x][y]=max(vis[x][y],dfs(xx,yy)+1);
			}
		}
	}
	if(ff){
		if(s[x][y]=='A')vis[x][y]=1;
		else vis[x][y]=0;
	}
	if(s[x][y]=='D')vis2[x][y]=1;
	return vis[x][y];
}

int main(){
	memset(vis,-1,sizeof(vis));
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)scanf("%s",s[i]+1);
	int cnt=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(s[i][j]=='D'){
				cnt++;
				p[cnt].x=i;
				p[cnt].y=j;
			}
		}
	}
	int ans=0;
	memset(vis2,0,sizeof(vis2));
	for(i=1;i<=cnt&&f;i++){
		ans=max(ans,dfs(p[i].x,p[i].y));
	}
	if(!f)printf("Poor Inna!\n");
	else if(!ans)printf("Poor Dima!\n");
	else printf("%d\n",ans);
	return 0;
}
