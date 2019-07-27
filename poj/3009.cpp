#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;

int n,m;
int s[105][105];
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};
int ans;

void dfs(int x,int y,int t){
	if(t == 10)return;
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
		if(s[dx][dy] == 1)continue;
		bool win = 0;
		while(dx >= 1 && dx <= n && dy >= 1 && dy <= m){
			if(s[dx][dy] == 3){
				ans = min(ans, t+1);
				win = 1;
				break;
			}
			if(s[dx][dy] == 1)break;	
			dx += xx[i];
			dy += yy[i];
		}
		if(win)continue;
		if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
		s[dx][dy] = 0;
		dfs(dx - xx[i], dy - yy[i], t+1);
		s[dx][dy] = 1;
	}
}

void solve(){
	ans = INF;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%d",&s[i][j]);	
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == 2){
				dfs(i,j,0);
				if(ans == INF)ans = -1;
				printf("%d\n",ans);
				return;
			}
		}
	}
}

int main(){
	while(scanf("%d%d",&m,&n) && (n+m))solve();
	return 0;
}
