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

queue<node>q;
int n,m;
int s[105][105];
int vis[105][105];
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};

void bfs(int x, int y){
	vis[x][y] = 1;
	q.push(node{x,y});
	while(!q.empty()){
		node u = q.front();q.pop();
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
			if(vis[dx][dy] || s[dx][dy] == 0)continue;
			vis[dx][dy] = 1;
			q.push(node{dx,dy});
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%d",&s[i][j]);
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(vis[i][j] || s[i][j] == 0)continue;
			ans ++;
			bfs(i,j);
		}
	}
	printf("%d\n",ans);
	return 0;
}


