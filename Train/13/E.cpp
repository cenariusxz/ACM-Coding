#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;

struct point{
	int x,y,id,dir;
	bool operator < (const point a)const{
		return id<a.id;
	}
}p[20000];

struct tpoint{
	int x,y,dir;
	tpoint(){}
	tpoint(int a,int b,int c):x(a),y(b),dir(c){}
};

// 0 N  1 S  2 W  3 E

int d[55][55];
int c[55][55];
int id[55][55][4];
int cnt=0;

vector<int>v[20000][11];
vector<int>now;

void init(){
	memset(d,0,sizeof(d));
	memset(c,0,sizeof(c));
	memset(id,-1,sizeof(id));
}

void BFS(){
	for(int i=1;i<=cnt;++i){
		for(int j=0;j<=10;++j)v[i][j].clear();
		queue<tpoint>q;
		now.clear();
		now.push_back(p[i].id);
		for(int j=1;j<=10;++j){
			for(int k=0;k<now.size();++k)q.push(tpoint(p[now[k]].x,p[now[k]].y,p[now[k]].dir));
			now.clear();
			while(!q.empty()){
				tpoint u=q.front();
				q.pop();
				if(u.dir==0){
					int x,y;
					if(c[u.x][u.y]&(1<<0)){
						x=u.x,y=u.y+1;
						now.push_back(id[x][y][0]);
					}
					if(c[u.x][u.y]&(1<<2)){
						x=u.x-1,y=u.y;
						now.push_back(id[x][y][2]);
					}
					if(c[u.x][u.y]&(1<<3)){
						x=u.x+1,y=u.y;
						now.push_back(id[x][y][3]);
					}
				}
				if(u.dir==1){
					int x,y;
					if(c[u.x][u.y]&(1<<1)){
						x=u.x,y=u.y-1;
						now.push_back(id[x][y][1]);
					}
					if(c[u.x][u.y]&(1<<2)){
						x=u.x-1,y=u.y;
						now.push_back(id[x][y][2]);
					}
					if(c[u.x][u.y]&(1<<3)){
						x=u.x+1,y=u.y;
						now.push_back(id[x][y][3]);
					}
				}
				if(u.dir==2){
					int x,y;
					if(c[u.x][u.y]&(1<<2)){
						x=u.x-1,y=u.y;
						now.push_back(id[x][y][2]);
					}
					if(c[u.x][u.y]&(1<<0)){
						x=u.x,y=u.y+1;
						now.push_back(id[x][y][0]);
					}
					if(c[u.x][u.y]&(1<<1)){
						x=u.x,y=u.y-1;
						now.push_back(id[x][y][1]);
					}
				}
				if(u.dir==3){
					int x,y;
					if(c[u.x][u.y]&(1<<3)){
						x=u.x+1,y=u.y;
						now.push_back(id[x][y][3]);
					}
					if(c[u.x][u.y]&(1<<0)){
						x=u.x,y=u.y+1;
						now.push_back(id[x][y][0]);
					}
					if(c[u.x][u.y]&(1<<1)){
						x=u.x,y=u.y-1;
						now.push_back(id[x][y][1]);
					}
				}
			}
			sort(now.begin(),now.end());
			v[i][j].push_back(now[0]);
			for(int k=1;k<now.size();++k){
				if(now[k]!=now[k-1])v[i][j].push_back(now[k]);
			}
			now=v[i][j];
		}
	}
}

int main(){
	int n,t,x0,y0;
	while(scanf("%d%d%d%d",&n,&x0,&y0,&t)!=EOF){
		init();
		for(int i=1;i<=n;++i){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2){
				if(y1>y2)swap(y1,y2);
				for(int j=y1;j<=y2;++j){
					if(j!=y2)c[x1][j]|=(1<<0);
					if(j!=y1)c[x1][j]|=(1<<1);
					d[x1][j]|=(1<<0);
					d[x1][j]|=(1<<1);
				}
			}
			else{
				if(x1>x2)swap(x1,x2);
				for(int j=x1;j<=x2;++j){
					if(j!=x1)c[j][y1]|=(1<<2);
					if(j!=x2)c[j][y1]|=(1<<3);
					d[j][y1]|=(1<<2);
					d[j][y1]|=(1<<3);
				}
			}
		}
		cnt=0;
		for(int i=0;i<=50;++i){
			for(int j=0;j<=50;++j){
				for(int k=0;k<=3;++k){
					if(d[i][j]&(1<<k)){
						++cnt;
						id[i][j][k]=cnt;
						p[cnt].x=i;
						p[cnt].y=j;
						p[cnt].id=cnt;
						p[cnt].dir=k;
					}
				}
			}
		}
		BFS();

		queue<int>q;
		now.clear();
		if(c[x0][y0]&(1<<0))now.push_back(id[x0][y0][0]);
		if(c[x0][y0]&(1<<1))now.push_back(id[x0][y0][1]);
		if(c[x0][y0]&(1<<2))now.push_back(id[x0][y0][2]);
		if(c[x0][y0]&(1<<3))now.push_back(id[x0][y0][3]);
		for(int i=1;i<=t;++i){
			for(int j=0;j<now.size();++j)q.push(now[j]);
			now.clear();
			int dis;
			char s[10];
			int dir;
			scanf("%d%s",&dis,s);
			if(s[0]=='N')dir=0;
			if(s[0]=='S')dir=1;
			if(s[0]=='W')dir=2;
			if(s[0]=='E')dir=3;
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int j=0;j<v[u][dis].size();++j){
					point tmp=p[v[u][dis][j]];
					if(dir==tmp.dir){
						now.push_back(id[tmp.x][tmp.y][dir]);
					}
					else if( (c[tmp.x][tmp.y]&(1<<dir)) && tmp.dir!=(dir^1) ){
						now.push_back(id[tmp.x][tmp.y][dir]);
					}
				}
			}
			sort(now.begin(),now.end());
			vector<int>tmp;
			tmp.push_back(now[0]);
			for(int j=1;j<now.size();++j){
				if(now[j]!=now[j-1])tmp.push_back(now[j]);
			}
			now=tmp;
		}
		printf("%d %d\n",p[now[0]].x,p[now[0]].y);
		for(int i=1;i<now.size();++i){
			if(p[now[i]].x!=p[now[i-1]].x||p[now[i]].y!=p[now[i-1]].y)printf("%d %d\n",p[now[i]].x,p[now[i]].y);
		}

	}
	return 0;
}
