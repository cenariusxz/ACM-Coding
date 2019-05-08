#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

char s[maxn][maxn];
int ans[maxn][maxn],vis[maxn][maxn],t;
int n,m;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};


void dfs(int x,int y){
	vis[x][y] = 1;
	t++;
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > n || vis[dx][dy])continue;
		if(s[x][y] == s[dx][dy])continue;
		dfs(dx,dy);
	}
}

void dfs2(int x,int y){
	vis[x][y] = 0;
	ans[x][y] = t;
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > n || vis[dx][dy] == 0)continue;
		dfs2(dx,dy);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
	memset(ans,0,sizeof(ans));
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(ans[x][y]){
			printf("%d\n",ans[x][y]);
			continue;
		}
		t=0;
		dfs(x,y);
		dfs2(x,y);
		printf("%d\n",ans[x][y]);
	}
	return 0;
}

