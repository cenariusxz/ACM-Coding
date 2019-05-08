#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int num,fa[105],c,d[55][55];
int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};
char g[55][55];
bool vis[55][55];

struct point{
	int x,y;
}p[105];

struct node{
	int x,y,s;
};

struct seg{
	int a,b,l;
	bool operator <(const seg a)const{
		return l<a.l;
	}
}s[105*105];

void init(){
	for(int i=1;i<=num;i++)fa[i]=i;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void bfs(int a){
	int i;
	memset(vis,0,sizeof(vis));
	queue<node>q;
	node u;
	u.x=p[a].x;
	u.y=p[a].y;
	u.s=0;
	q.push(u);
	vis[u.x][u.y]=1;
	while(!q.empty()){
		node tmp=q.front();
		q.pop();
		if(d[tmp.x][tmp.y]&&d[tmp.x][tmp.y]!=a){
			s[++c].a=a;
			s[c].b=d[tmp.x][tmp.y];
			s[c].l=tmp.s;
		}
		for(i=0;i<4;i++){
			int dx=tmp.x+xx[i],dy=tmp.y+yy[i];
			if(!vis[dx][dy]&&g[dx][dy]!='#'){
				u.x=dx;
				u.y=dy;
				u.s=tmp.s+1;
				q.push(u);
				vis[dx][dy]=1;
			}
		}
	}
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			int n,m;
			c=0;
			scanf("%d%d",&n,&m);
			int i,j;
			memset(g,0,sizeof(g));
			memset(d,0,sizeof(d));
			gets(g[0]);
			for(i=1;i<=m;i++)gets(g[i]);
			num=0;
			for(i=1;i<=m;i++){
				for(j=0;j<n;j++){
					if(g[i][j]=='A'||g[i][j]=='S'){
						p[++num].x=i;
						p[num].y=j;
						d[i][j]=num;
					}
				}
			}
			init();
			for(i=1;i<=num;i++){
				bfs(i);
			}
			int ans=0,t=0;
			sort(s+1,s+c+1);
			for(i=1;i<=c;i++){
				int x=find(s[i].a),y=find(s[i].b);
				if(x!=y){
					fa[x]=y;
					t++;
					ans+=s[i].l;
					if(t==num-1)break;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
