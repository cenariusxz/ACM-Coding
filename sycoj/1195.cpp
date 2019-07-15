#include <bits/stdc++.h>
using namespace std;

int xx[8] = {-1,-1,-1,0,0,1,1,1};
int yy[8] = {-1,0,1,-1,1,-1,0,1};

int n,m,a[10][10],vis[10][10],ans;
int T;

void dfs(int x,int y,int sum){
	if(x == n && y == m){
		ans = max(ans,sum);
		return;
	}
	y ++ ;
	if(y == m+1)x++, y=1;
	dfs(x,y,sum);
	for(int i = 0 ; i < 8 ;  ++ i){
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
		if(vis[dx][dy])return;
	}
	vis[x][y] = 1;
	dfs(x,y,sum+a[x][y]);
	vis[x][y] = 0;
}

int main(){
    scanf("%d",&T);
    while(T--){
        ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1 ; i <= n ; ++ i){
            for(int j = 1 ; j <= m ; ++ j){
                scanf("%d",&a[i][j]);
                vis[i][j] = 0;
            }
        }
        dfs(1,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
