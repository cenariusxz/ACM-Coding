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

int n,m;
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};
char s[205][205];
int vis[205][205];

void bfs(int x,int y){
	queue<node>q;
	vis[x][y] = 1;
	q.push(node{x,y,0});
	while(!q.empty()){
		node u = q.front();q.pop();
		if(s[u.x][u.y] == 'E'){
			printf("%d\n",u.t);
			return;
		}
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
			if(vis[dx][dy])continue;
			if(s[dx][dy] == '#')continue;
			vis[dx][dy] = 1;
			q.push(node{dx,dy,u.t+1});	
		}
	}
	printf("oop!\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
		int x,y;
		for(int i = 1 ; i <= n ; ++ i){
			for(int j = 1 ; j <= m ; ++ j){
				if(s[i][j] == 'S')bfs(i,j);
			}
		}
	}
	return 0;
}
