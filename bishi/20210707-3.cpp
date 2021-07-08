#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, y;
};
queue<node> q;

int xx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int yy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int nx[8] = {-1, -1, 0, 0, 0, 0, 1, 1};
int ny[8] = {0, 0, 1, -1, 1, -1, 0, 0};
int w, h, d[155][155], sx, sy;
char s[155][155];

int bfs(){
	memset(d, -1, sizeof(d));
	d[sx][sy] = 0;
	q.push(node{sx, sy});
	while(!q.empty()){
		node u = q.front(); q.pop();
		for(int i = 0 ; i < 8 ; ++ i){
			int dx = u.x + xx[i], dy = u.y + yy[i];
			int tx = u.x + nx[i], ty = u.y + ny[i];
			if(dx < 1 || dx > w || dy < 1 || dy > h)continue;
			if(d[dx][dy] != -1)continue;
			if(s[dx][dy] == '#' || s[tx][ty] == '#')continue;
			d[dx][dy] = d[u.x][u.y] + 1;
			if(s[dx][dy] == 'T')return d[dx][dy];
			q.push(node{dx, dy});
		}
	}
	return -1;
}

int main(){
	scanf("%d%d", &w, &h);
	for(int i = 1 ; i <= w ; ++ i)scanf("%s", s[i] + 1);
	for(int i = 1 ; i <= w ; ++ i){
		for(int j = 1 ; j <= h ; ++ j){
			if(s[i][j] == 'H')sx = i, sy = j;
		}
	}
	printf("%d\n", bfs());
	return 0;
}

