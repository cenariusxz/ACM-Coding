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
	int x,y,t;
};

int vis[305][305];
int xx[12] = {-2,-2,-1,-1,1,1,2,2,-2,-2,2,2};
int yy[12] = {-1,1,-2,2,-2,2,-1,1,-2,2,-2,2};

void bfs(int x1,int y1,int x2,int y2){
	queue<node>q;
	vis[x1][y1] = 1;
	q.push(node{x1,y1,0});
	while(!q.empty()){
		node u = q.front();q.pop();
		if(u.x == x2 && u.y == y2){
			printf("%d\n",u.t);
			return;
		}
		for(int i = 0 ; i < 12 ; ++ i){
			int dx = u.x + xx[i], dy = u.y + yy[i];
			if(dx < 1 || dx > 150 || dy < 1 || dy > 150)continue;
			if(vis[dx][dy])continue;
			vis[dx][dy] = 1;
			q.push(node{dx,dy,u.t+1});	
		}
	}
}

int main(){	
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	memset(vis,0,sizeof(vis));
	bfs(x1,y1,1,1);
	memset(vis,0,sizeof(vis));
	bfs(x2,y2,1,1);
	return 0;
}
