#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 25;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int vis[maxn][maxn],ans = 0;
int n,m;
int xx[8] = {-2,-2,-1,-1,1,1,2,2};
int yy[8] = {-1,1,-2,2,-2,2,-1,1};

void dfs(int x,int y,int step){
	if(step == n*m)ans++;
	for(int i = 0 ; i < 8 ; ++ i){
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
		if(vis[dx][dy])continue;
		vis[dx][dy] = 1;
		dfs(dx,dy,step+1);
		vis[dx][dy] = 0;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		ans = 0;
		int x,y;
		scanf("%d%d%d%d",&n,&m,&x,&y);
		x++;y++;
		vis[x][y] = 1;
		dfs(x,y,1);
		printf("%d\n",ans);
	}
	return 0;
}

