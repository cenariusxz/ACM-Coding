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
node ans[105][105];

int vis[105][105],n=5;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
int M[105][105];

void bfs(int x,int y){
	queue<node>q;
	vis[x][y] = 1;
	q.push(node{x,y});
	while(!q.empty()){
		node u = q.front();q.pop();
		M[u.x][u.y] = 2;
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > n)continue;
			if(vis[dx][dy]||M[dx][dy] == 1)continue;
			vis[dx][dy] = 1;
			q.push(node{dx,dy});	
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			scanf("%d",&M[i][j]);
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(!vis[1][i] && M[1][i] == 0)bfs(1,i);
		if(!vis[n][i] && M[n][i] == 0)bfs(n,i);
		if(!vis[i][1] && M[i][1] == 0)bfs(i,1);
		if(!vis[i][n] && M[i][n] == 0)bfs(i,n);
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			if(M[i][j] == 0)printf("2 ");
			if(M[i][j] == 2)printf("0 ");
			if(M[i][j] == 1)printf("1 ");
		}
		printf("\n");
	}
	return 0;
}

