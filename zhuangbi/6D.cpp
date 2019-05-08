#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f;

struct point{
	int x,y,t,s;
	bool operator<(const point a){
		return t>a.t;
	}
	point(int a,int b,int c,int d=0):x(a),y(b),t(c),s(d){}
};

struct snake{
	int x,y;
}S[10];
int mas[105][105];
int dp[105][105][50];
int vis[105][105][50];
char ma[105][105];
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
vector<point>v[15];

void init(){
	memset(mas,0,sizeof(mas));
	memset(dp,0x3f,sizeof(dp));
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		init();
		for(int i=1;i<=n;++i)scanf("%s",ma[i]+1);
			memset(vis,0,sizeof(vis));
		int scnt=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(ma[i][j]=='K'){
					v[0].push_back(point(i,j,0));
					dp[i][j][0]=0;
				}
				else if(ma[i][j]=='T'){
					ma[i][j]='0'+m+1;
					v[m+1].push_back(point(i,j,INF));
				}
				else if(ma[i][j]=='S'){
					scnt++;
					S[scnt].x=i;
					S[scnt].y=j;
					mas[i][j]=scnt;
				}
			}
		}
		for(int i=0;i<=m;++i){
			priority_queue<point>q;
			memset(vis,0,sizeof(vis));
			for(int j=0;j<v[i].size();++j){
				q.push(v[i][j]);
				vis[v[i][j].x][v[i][j].y][v[i][j].s]=1;
			}
			while(!q.empty()){
				point u=q.top();q.pop();
				for(int j=0;j<4;++j){
					int dx=u.x+xx[j],dy=u.y+yy[j];
					if(dx>=1&&dx<=n&&dy>=1&&dy<=n){
						if(ma[dx][dy]=='#')continue;
						if(ma[dx][dy]=='0'+i+1){
							dp[dx][dy][u.s]=min(dp[dx][dy][u.s],u.t+1);
						}
						if(ma[dx][dy]=='S'){
							int num=mas[dx][dy];
							int t,s;
							if(u.s&(1<<(num-1))){
								t=u.t+1;
								s=u.s;
							}
							else{
								t=u.t+2;
								s=u.s+(1<<(num-1));
							}
							if()
						}
					}
				}
			}
		}
	}
	return 0;
}
