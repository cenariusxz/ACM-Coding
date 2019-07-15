#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 115;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

struct node{
	int x,y;
};

int vis[maxn][maxn],n,m;
char s[maxn][maxn];
int xx[8] = {0,0,1,-1,1,1,-1,-1};
int yy[8] = {1,-1,0,0,1,-1,1,-1};

void bfs(int x, int y){
	queue<node>q;
	vis[x][y] = 1;
	q.push(node{x,y});
	while(!q.empty()){
		node u = q.front();q.pop();
		for(int i = 0 ; i < 8 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
			if(vis[dx][dy])continue;
			if(s[dx][dy] == '.')continue;
			vis[dx][dy] = 1;
			q.push(node{dx,dy});	
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == 'W' && !vis[i][j]){
				bfs(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
