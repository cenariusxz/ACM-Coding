#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct point{
	int x,y;
}p[15];

typedef struct Node {
	int x, y, t;
}node;

int d[105][105];
bool vi[105][105];
int dist[15][15];
int n,m, cnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int z){
	memset(vi,0,sizeof(vi));
	queue<node>q;
	while (!q.empty()) q.pop();
	node s; 
	s.x = p[z].x; s.y = p[z].y; s.t = 0;
	q.push(s);
	vi[p[z].x][p[z].y]=1;

	while (!q.empty()) {
		node cur = q.front(); q.pop();
		for (int j = 1; j <= cnt; j++) {
			if (cur.x == p[j].x && cur.y == p[j].y)
				dist[z][j] = dist[j][z]=min(dist[z][j],cur.t);
		}

		for (int i = 0; i < 4; i++) {
			int x = dx[i] + cur.x;
			int y = dy[i] + cur.y;
			if (x < 1 || x > n || y < 1 || y > m || d[x][y] < 0) 
				continue;
			if (vi[x][y]) continue;
			vi[x][y] = 1;
			node nxt; 
			nxt.x = x; nxt.y = y; nxt.t = cur.t + 1;
			q.push(nxt);
		}
	}
}

void Min(int &x, int y) {
	if (x > y)
		x = y;
}

int dp[2050][15];
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(p,0,sizeof(p));
		memset(d,0,sizeof(d));
		int i,j;
		cnt=0;
		p[++cnt].x=1;
		p[cnt].y=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&d[i][j]);
				if(d[i][j]>0&&(i!=1||j!=1)){
					p[++cnt].x=i;
					p[cnt].y=j;
				}
			}
		}
		memset(dist,0x3f,sizeof(dist));
		for(i=1;i<=cnt;i++){
			bfs(i);
		}
		memset(dp, 0x3f, sizeof(dp));
		dp[1][1] = 0;
		for (int i = 3; i < (1<<cnt); i++) {
			if(i&1){
				for (int j = 1; j < cnt; j++) if (i & (1<<j)) {
					for (int k = 0; k < cnt; k++) if ((i^(1<<j)) & (1<<k)) {
						Min(dp[i][j+1], dp[i^(1<<j)][k+1] + dist[k+1][j+1]);
					}
				}
			}	
		}
		int ans = 0x3f3f3f3f;
		for (int i = 1; i <= cnt; i++) 
			Min(ans, dp[(1<<cnt)-1][i] + dist[i][1]);
		if (d[1][1] < 0 || ans == 0x3f3f3f3f) ans = -1;
		printf("%d\n", ans);
	}

	return 0;
}
