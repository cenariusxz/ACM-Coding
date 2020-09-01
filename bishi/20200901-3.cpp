#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 25000 + 5;

struct node{
	int c, v;
	bool operator < (const node a)const{
		return c < a.c;
	}
}nd[205];

int n, m, dp[2][maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &nd[i].c, &nd[i].v);
	sort(nd + 1, nd + 1 + n);
	int mx = m, now, pre, ans = 0;
	for(int i = 1 ; i <= n ; ++ i)if(nd[i].c < 0)mx -= nd[i].c;
	for(int i = 0 ; i <= mx ; ++ i)dp[0][i] = (i <= m ? 0 : -INF);
	for(int i = 1 ; i <= n ; ++ i){
		now = i & 1; pre = now ^ 1;
		for(int j = 0 ; j <= mx ; ++ j)dp[now][j] = dp[pre][j];
		for(int j = max(0, -nd[i].c) ; j <= min(mx, mx - nd[i].c) ; ++ j){	// fix
			dp[now][j] = max(dp[now][j], dp[pre][j + nd[i].c] + nd[i].v);
		}
	}
	now = n & 1;
	for(int i = 0 ; i <= mx ; ++ i)ans = max(ans, dp[now][i]);
	printf("%d\n", ans);
	return 0;
}

