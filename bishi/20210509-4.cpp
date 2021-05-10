#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, y, f, t;
	node(){}
	node(int _x, int _y, int _f, int _t):x(_x), y(_y), f(_f), t(_t){}
};

char s[505][505];
int n, m, vis[505][505][2];
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
queue<node>q;

int solve(){
	vis[1][1][1] = 1;
	q.push(node(1,1,1,0));
	while(!q.empty()){
		node u = q.front();q.pop();
		if(u.x == n && u.y == m)return u.t;
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
			if(s[dx][dy] == '.' && !vis[dx][dy][u.f]){
				vis[dx][dy][u.f] = 1;
				q.push(node(dx, dy, u.f, u.t+1));
			}
			else if(u.f == 1 && !vis[dx][dy][0]){
				vis[dx][dy][0] = 1;
				q.push(node(dx, dy, 0, u.t+1));
			}
		}
	}
	return -1;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i]+1);
	printf("%d\n", solve());
	return 0;
}

