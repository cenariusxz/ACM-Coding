#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

bool vis[505][505];

struct point{
	int x,y;
	point(int a,int b):x(a),y(b){}
};

int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,-1,1};

int ddx[4][2]={1,0,1,0,-1,0,-1,0};
int ddy[4][2]={0,1,0,-1,0,-1,0,1};

int main(){
	int T;
	scanf("%d",&T);
	for(int Q=1;Q<=T;Q++){
		memset(vis,0,sizeof(vis));
		int n,m,g,i,j,ans=0;
		scanf("%d%d%d",&n,&m,&g);
		queue<point>q;
		for(i=1;i<=g;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(!vis[a][b]){
				vis[a][b]=1;
				q.push(point(a,b));
				ans++;
			}
		}
		while(!q.empty()){
			point u=q.front();
			q.pop();
			for(i=0;i<4;i++){
				int x=u.x+dx[i],y=u.y+dy[i];
				if(x>=1&&x<=n&&y>=1&&y<=m&&vis[x][y]){
					for(j=0;j<2;j++){
						int xx=u.x+ddx[i][j],yy=u.y+ddy[i][j];
						if(!vis[xx][yy]){
							vis[xx][yy]=1;
							q.push(point(xx,yy));
							ans++;
						}
					}
				}
			}
		}
		printf("Case #%d:\n%d\n",Q,ans);
	}
	return 0;
}
