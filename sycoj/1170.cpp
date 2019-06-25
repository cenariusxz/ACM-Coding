#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

struct node{
	int x,y,t;	
};
int n = 100;
int vis[maxn][maxn];
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
			if(dx < 1 || dx > n || dy < 1 || dy > n)continue;
			if(vis[dx][dy])continue;
			vis[dx][dy] = 1;
			q.push(node{dx,dy,u.t+1});		
		}
	}
}

int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	memset(vis,0,sizeof(vis));
	bfs(x,y,1,1);
	scanf("%d%d",&x,&y);
	memset(vis,0,sizeof(vis));
	bfs(x,y,1,1);
	return 0;
}

