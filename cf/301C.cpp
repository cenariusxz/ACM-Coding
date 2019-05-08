#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

char a[505][505];
bool vis[505][505];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct node{
	int x,y;
};

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
		int i,j;
		
		for(i=1;i<=n;i++){
			scanf("%s",a[i]+1);
		}
		int sx,sy,ex,ey;
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		queue<node>q;
		node temp;
		temp.x=sx;
		temp.y=sy;
		q.push(temp);
		bool f=1;
		while(!q.empty()&&f){
			node tmp=q.front();
			q.pop();
			for(i=0;i<4&&f;i++){
				node t;
				t.x=tmp.x+dx[i];
				t.y=tmp.y+dy[i];
				if(t.x>=1&&t.x<=n&&t.y>=1&&t.y<=m){
					if(t.x==ex&&t.y==ey){
						if(a[t.x][t.y]=='X')f=0;
						else{
							q.push(t);
							a[t.x][t.y]='X';
						}
					}
					else if(a[t.x][t.y]=='.'){
						q.push(t);
						a[t.x][t.y]='X';
					}
				}
			}
		}
		if(f)printf("NO\n");
		else printf("YES\n");
	return 0;
}
