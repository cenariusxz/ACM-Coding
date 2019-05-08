#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
};

int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
int M[35][35],vis[35][35];
int n;

void BFS(int x,int y){
	queue<node>q;
	q.push(node{x,y});
	vis[x][y] = 1;
	while(!q.empty()){
		node u = q.front();q.pop();
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i];
			int dy = u.y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > n)continue;
			if(vis[dx][dy] || M[dx][dy] == 1)continue;
			q.push(node{dx,dy});
			vis[dx][dy] = 1;
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
		if(!vis[1][i] && M[1][i] == 0)BFS(1,i);
		if(!vis[n][i] && M[n][i] == 0)BFS(n,i);
		if(!vis[i][1] && M[i][1] == 0)BFS(i,1);
		if(!vis[i][n] && M[i][n] == 0)BFS(i,n);
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			if(!vis[i][j] && M[i][j] == 0)printf("2");
			else printf("%d",M[i][j]);
			if(j == n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
