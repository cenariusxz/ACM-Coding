#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

struct node{
	int x,y,d,t;
	node(int a,int b,int c,int e):x(a),y(b),d(c),t(e){}
};

int point[105][105];
int px[105],py[105],pt[105];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	int r,c,n,T;
	while(scanf("%d",&r)!=EOF){
		c=read();
		n=read();
		T=read();
		int i;
		int cnt=0;
		memset(point,0,sizeof(point));
		memset(pt,0,sizeof(pt));
		for(i=1;i<=n;i++){
			px[i]=read();
			py[i]=read();
			point[px[i]][py[i]]=read();
		}
		int x=read();
		int y=read();
		queue<node>q;
		for(i=0;i<4;i++)q.push(node(x,y,i,0));
		for(i=1;i<=T;i++){
			while(!q.empty()){
				node u=q.front();
				if(u.t==i)break;
				q.pop();
				int xx=u.x+dx[u.d];
				int yy=u.y+dy[u.d];
				if(xx>=1&&xx<=r&&yy>=1&&yy<=c){
					if(point[xx][yy])point[xx][yy]++;
					else{
						q.push(node(xx,yy,u.d,i));
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(pt[j])continue;
				if(point[px[j]][py[j]]>4){
					cnt++;
					for(int k=0;k<4;k++)q.push(node(px[j],py[j],k,i));
					point[px[j]][py[j]]=0;
					pt[j]=i;
				}
			}
			if(cnt==n)break;
		}
		for(i=1;i<=n;i++){
			if(point[px[i]][py[i]])printf("1 %d\n",point[px[i]][py[i]]);
			else printf("0 %d\n",pt[i]);
		}
	}
	return 0;
}
