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

char s[50][50];
int n,m,vis[50][50];
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};

void bfs(){
	queue<node>q;
	vis[1][1] = 1;
	q.push(node{1,1,1});
	while(!q.empty()){
		node u = q.front();q.pop();
		if(u.x == n && u.y == m){
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
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
	bfs();
	return 0;
}
