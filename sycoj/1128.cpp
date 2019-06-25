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

int n,k;
char s[10][10];
int vis[10][10];
int ans = 0;

void dfs(int x,int y,int sum){
	if(x == n && y == n)return;
	y++;
	if(y == n+1)x++, y = 1;
	if(s[x][y] == '.'){
		dfs(x,y,sum);
		return;	
	}
	int dx = x - 1, dy = y;
	while(1){
		if(dx < 1)break;
		if(vis[dx][dy]){
			dfs(x,y,sum);
			return;
		}
		dx --;
	}
	dx = x, dy = y - 1;
	while(1){
		if(dy < 1)break;
		if(vis[dx][dy]){
			dfs(x,y,sum);
			return;
		}
		dy --;
	}
	dfs(x,y,sum);
	vis[x][y] = 1;
	sum ++;
	if(sum == k)ans++;
	else dfs(x,y,sum);
	vis[x][y] = 0;
}

int main(){
	while(scanf("%d%d",&n,&k)){
		if(n == -1 && k == -1)break;
		for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
		ans = 0;
		memset(vis,0,sizeof(vis));
		dfs(1,0,0);
		printf("%d\n",ans);
	}
	return 0;
}


