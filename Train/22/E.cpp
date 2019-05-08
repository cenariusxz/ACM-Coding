#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 30;

int T,N,ans;
int G[MAXN][MAXN];
int vis[MAXN][MAXN];
int dir[4][2] = {{1,-1},{1,0},{1,1},{0,1}};

void Dfs(int x,int y,int cnt,int sum){
	ans = max(ans,cnt);
	if(x > N) return;
	int tx = x,ty = y + 1;
	if(ty > N){
		tx++;
		ty = 1;
	}
	if(G[x][y] || vis[x][y]) Dfs(tx,ty,cnt,sum);
	else{
		if(cnt + sum <= ans) return;
		int cc = 0;
		for(int k = 0; k < 4; ++k){
			int vx = x,vy = y;
			while(vx >= 1 && vx <= N && vy >= 1 && vy <= N){
				if(G[vx][vy]) break;
				if(vis[vx][vy] == 0) cc++;
				vis[vx][vy]++;
				vx += dir[k][0];
				vy += dir[k][1];
			}
		}
		Dfs(tx,ty,cnt + 1,sum - cc);
		for(int k = 0; k < 4; ++k){
			int vx = x,vy = y;
			while(vx >= 1 && vx <= N && vy >= 1 && vy <= N){
				if(G[vx][vy]) break;
				vis[vx][vy]--;
				vx += dir[k][0];
				vy += dir[k][1];
			}
		}
		Dfs(tx,ty,cnt,sum - 1);
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&N);
		int sum = N * N;
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= N; ++j){
				scanf("%d",&G[i][j]);
				sum -= G[i][j];
			}
		}
		ans = 0;
		Dfs(1,1,0,sum);
		printf("%d\n",ans);
	}
	return 0;
}

