#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int a[20][20];
int vis[20],dp[20][20],que[20],qcnt;
int n,m,r,c,ans;

void solve(){
	memset(dp,0x3f,sizeof(dp));
	dp[0][0] = 0;
	int point1,point2;
	for(int i = 1 ; i <= m ; ++ i){
		point1 = 0;
		for(int j = 2 ; j <= qcnt ; ++ j){
			point1 += abs( a[que[j]][i] - a[que[j-1]][i] );
		}
		int lim = min(i,c);
		for(int j = 1 ; j <= lim ; ++ j){
			for(int k = 0 ; k < i ; ++ k){
				point2 = 0;
				if(k){
					for(int p = 1 ; p <= qcnt ; ++ p){
						point2 += abs( a[que[p]][i] - a[que[p]][k] );
					}
				}
				dp[i][j] = min(dp[i][j],dp[k][j-1] + point1 + point2);
			}
		}
	}
	for(int i = 1 ; i <= m ; ++ i){
		ans = min(ans,dp[i][c]);
	}
}

int main(){
	ans = INF;
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1 ; i < (1<<n) ; ++ i){
		int bits = 0;
		qcnt = 0;
		for(int j = 1 ; j <= n ; ++ j){
			if(i & (1 << (j-1)) ){
				bits++;
				que[++qcnt] = j;
			}
		}
		if(bits == r)solve();
	}
	printf("%d\n",ans);
	return 0;
}
