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

int r,c;
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};

char s[50][50];
int vis[maxn];
int ans = 0;

void dfs(int x,int y,int num){
	ans = max(ans,num);
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > r || dy < 1 || dy > c)continue;
		if(vis[s[dx][dy]])continue;
		vis[s[dx][dy]] = 1;
		dfs(dx,dy,num+1);
		vis[s[dx][dy]] = 0;
	}
}

int main(){
	scanf("%d%d",&r,&c);
	for(int i = 1 ; i <= r ; ++ i)scanf("%s",s[i]+1);
	vis[s[1][1]] = 1;
	dfs(1,1,1);
	printf("%d\n",ans);
	return 0;
}

