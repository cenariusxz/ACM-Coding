#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

struct node{
	int x,y;
};

int s[10][10],vis[10][10];
node ans[10][10];
int n = 5;
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};
 
void bfs(){
	queue<node>q;
	q.push(node{1,1});
	vis[1][1] = 1;
	while(!q.empty()){
		node u = q.front();
		q.pop();
		if(u.x == 5 && u.y == 5)break;
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			if(dx < 1 || dx > 5 || dy < 1 || dy > 5)continue;
			if(s[dx][dy] == 1)continue;
			if(vis[dx][dy])continue;
			q.push(node{dx,dy});
			vis[dx][dy] = 1;
			ans[dx][dy] = u; 
		}
	}
}

void dfs(int x,int y){
	if(x == 1 && y == 1){
		printf("(%d, %d)\n",x-1,y-1);
		return;
	}
	dfs(ans[x][y].x, ans[x][y].y);
	printf("(%d, %d)\n",x-1,y-1);
}

int main(){
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			scanf("%d",&s[i][j]);
		}
	}
	bfs();
	dfs(5,5);
	return 0;
}


