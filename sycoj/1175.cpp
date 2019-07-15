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
	int x,y,z,t;
};
int vis[25][25][25];
char s[25][25][25];
int n,m,d;
int xx[6] = {1,-1,0,0,0,0};
int yy[6] = {0,0,1,-1,0,0};
int zz[6] = {0,0,0,0,1,-1};

void bfs(int x,int y,int z){
	queue<node>q;
	vis[x][y][z] = 1;
	q.push(node{x,y,z,0});
	while(!q.empty()){
		node u = q.front();q.pop();
		if(s[u.x][u.y][u.z] == 'E'){
			printf("Escaped in %d minute(s).\n",u.t);
			return;	
		}
		for(int i = 0 ; i < 6 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			int dz = u.z + zz[i];	
			if(dx < 1 || dx > n || dy < 1 || dy > m || dz < 1 || dz > d)continue;
			if(vis[dx][dy][dz])continue;
			if(s[dx][dy][dz] == '#')continue;
			vis[dx][dy][dz] = 1;
			q.push(node{dx,dy,dz,u.t+1});
		}
	}
	printf("Trapped!\n");
}

int main(){
	scanf("%d%d%d",&n,&m,&d);
	memset(vis,0,sizeof(vis));
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%s",s[i][j]+1); 
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			for(int k = 1 ; k <= d ; ++ k){
				if(s[i][j][k] == 'S'){
					bfs(i,j,k);	
				}
			}
		}
	}
	return 0;
}
