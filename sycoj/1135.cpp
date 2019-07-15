#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int xx[8] = {-2,-2,-1,-1,1,1,2,2};
int yy[8] = {-1,1,-2,2,-2,2,-1,1};

int n,m,x,y,ans = 0;
int vis[15][15];

void dfs(int x,int y,int sum){
	if(sum == n*m){
		ans++;
		return;	
	}
	for(int i = 0 ; i < 8 ; ++ i){
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
		if(vis[dx][dy])continue;
		vis[dx][dy] = 1;
		dfs(dx,dy,sum+1);
		vis[dx][dy] = 0;
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	x++;y++;
	vis[x][y] = 1;
	dfs(x,y,1);
	printf("%d\n",ans);
	return 0;
	
}

