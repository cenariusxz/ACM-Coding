#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

struct node{
	int x,y;	
};

int r,c;
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};
char s[1005][1005];
int vis[1005][1005];

bool bfs(int x, int y){
	queue<node>q;
	int minx = x, maxx = x, miny = y, maxy = y;
	q.push(node{x,y});
	vis[x][y] = 1;
	while(!q.empty()){
		node u = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			if(dx < 1 || dx > r || dy < 1 || dy > c)continue;
			if(vis[dx][dy] || s[dx][dy] == '.')continue;
			vis[dx][dy] = 1;
			minx = min(minx, dx);
			maxx = max(maxx, dx);
			miny = min(miny, dy);
			maxy = max(maxy, dy);
			q.push(node{dx,dy});
		}
	}
	for(int i = minx ; i <= maxx ; ++ i){
		for(int j = miny ; j <= maxy ; ++ j){
			if(s[i][j] == '.')return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%d%d",&r,&c);
	for(int i = 1 ; i <= r ; ++ i)scanf("%s", s[i] + 1);
	int ans = 0;
	for(int i = 1 ; i <= r ; ++ i){
		for(int j = 1 ; j <= c ; ++ j){
			if(vis[i][j] || s[i][j] == '.')continue;
			if(bfs(i,j) == 0){
				printf("Bad placement.\n");
				return 0;
			}
			ans++;
		}
	}
	printf("There are %d ships.\n",ans);
	return 0;
}


