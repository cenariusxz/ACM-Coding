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
int row[MAXN][MAXN],col[MAXN][MAXN];
int dig1[MAXN][MAXN],dig2[MAXN][MAXN];
int rc,cc,dc1,dc2;
int vr[MAXN * MAXN],vc[MAXN * MAXN],vd1[MAXN * MAXN];
int vd2[MAXN * MAXN];

void Dfs(int x,int y,int cnt,int top){
	ans = max(ans,cnt);
	if(x == N + 1) return;
	int tx = x,ty = y + 1;
	if(ty > N){
		tx++;
		ty = 1;
	}
	if(G[x][y]) Dfs(tx,ty,cnt,top);
	else{
		if(cnt + top <= ans) return;
		if(!vr[row[x][y]] && !vc[col[x][y]] && !vd1[dig1[x][y]] &&
				!vd2[dig2[x][y]]){
			vr[row[x][y]] = vc[col[x][y]] = vd1[dig1[x][y]] = 
				vd2[dig2[x][y]] = 1;
			Dfs(tx,ty,cnt + 1,top - 1);
			vr[row[x][y]] = vc[col[x][y]] = vd1[dig1[x][y]] = 
				vd2[dig2[x][y]] = 0;
		}
		Dfs(tx,ty,cnt,top);
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i)
			for(int j = 1; j <= N; ++j)
				scanf("%d",&G[i][j]);
		rc = cc = dc1 = dc2 = 1;
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= N; ++j){
				if(G[i][j]) rc++;
				else row[i][j] = rc;
			}
			rc++;
		}
		for(int j = 1; j <= N; ++j){
			for(int i = 1; i <= N; ++i){
				if(G[i][j]) cc++;
				else col[i][j] = cc;
			}
			cc++;
		}
		for(int i = N; i >= 1; --i){
			int x = i,y = 1;
			while(x <= N && y <= N){
				if(G[x][y]) dc1++;
				else dig1[x][y] = dc1;
				x++; y++;
			}
			dc1++;
		}
		for(int j = 2; j <= N; ++j){
			int x = 1,y = j;
			while(x <= N && y <= N){
				if(G[x][y]) dc1++;
				else dig1[x][y] = dc1;
				x++; y++;
			}
			dc1++;
		}
		for(int i = 1; i <= N; ++i){
			int x = i,y = 1;
			while(x >= 1 && y <= N){
				if(G[x][y]) dc2++;
				else dig2[x][y] = dc2;
				x--; y++;
			}
			dc2++;
		}
		for(int j = 2; j <= N; ++j){
			int x = N,y = j;
			while(x >= 1 && y <= N){
				if(G[x][y]) dc2++;
				else dig2[x][y] = dc2;
				x--; y++;
			}
			dc2++;
		}
		ans = 0;
		int now = min(rc,min(cc,min(dc1,dc2)));
		Dfs(1,1,0,now);
		printf("%d\n",ans);
	}
	return 0;
}
