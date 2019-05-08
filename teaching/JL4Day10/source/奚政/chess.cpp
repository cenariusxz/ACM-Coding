#include <bits/stdc++.h>
using namespace std;

int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};

char s[10][10];
int idx[20],idy[20];
int n,m,ans = 0;

void dfs(int now,int num){
	if(now == n*m+1){
		ans = max(ans,num);
		return;
	}
	dfs(now+1,num);
	int x = idx[now], y = idy[now];
	if(s[x][y] == '#')return;
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = x, dy = y;
		while(1){
			dx += xx[i], dy += yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > m)break;
			if(s[dx][dy] == '#')break;
			if(s[dx][dy] == '*')return;
		}
	}
	s[x][y] = '*';
	dfs(now+1,num+1);
	s[x][y] = '.';
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			cnt++;
			idx[cnt] = i; idy[cnt] = j;
		}
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
