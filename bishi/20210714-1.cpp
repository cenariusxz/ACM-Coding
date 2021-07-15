#include <bits/stdc++.h>
using namespace std;

int n, m, vis[1300][1300], ans;
char s[1300][1300], t[3];
int xx[6] = {-1, 0, 1, 1, 0, -1};
int yy[6] = {0, -1, -1, 0, 1, 1};

void dfs(int x, int y){
	vis[x][y] = 1;
	for(int i = 0 ; i < 6 ; ++ i){
		int dx = x + xx[i], dy = y + yy[i];
		if(dx < 1 || dx > m || dy < 1 || dy > n)continue;
		if(s[dx][dy] == 'P' || vis[dx][dy])continue;
		dfs(dx, dy);
	}
}

int main(){
	scanf("%d%d", &m, &n);
	for(int i = 1 ; i <= m ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			scanf("%s", t);
			s[i][j] = t[0];
		}	
	}
	for(int i = 1 ; i <= m ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			if(s[i][j] == 'C' && !vis[i][j]){
				dfs(i, j);
				++ ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

