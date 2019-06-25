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

int xx[8] = {-1,-1,-1,0,0,1,1,1};
int yy[8] = {-1,0,1,-1,1,-1,0,1};
int n,s[12][12],vis[12][12];
int ans = 0; 

void dfs(int x,int y){
	if(x == 1 && y == n){
		ans++;
		return;
	}
	for(int i = 0 ; i < 8 ; ++ i){
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > n)continue;
		if(s[dx][dy] == 1 || vis[dx][dy])continue;
		vis[dx][dy] = 1;
		dfs(dx,dy);
		vis[dx][dy] = 0;
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			scanf("%d",&s[i][j]);
		}
	}
	vis[1][1] = 1;
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}


