#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

struct node{
	int lv, x, y;
	bool operator < (const node a)const{
		if(lv == a.lv && y == a.y)return x < a.x;
		if(lv == a.lv)return y > a.y;
		return lv < a.lv;
	}
}nd[maxn], lvnd[maxn][2];

int n;
int lv[maxn], lvcnt;
ll dp[maxn][2];

ll cal(node a, node b){
	return abs((ll)(a.x - b.x)) + abs((ll)(a.y - b.y));
}

void solve(){
	for(int i = 1 ; i <= n ; ++ i)nd[i].lv = max(nd[i].x, nd[i].y);
	sort(nd + 1, nd + 1 + n);
	for(int i = 1 ; i <= n ; ++ i){
		if(nd[i].lv != lv[lvcnt]){
			lvcnt++;
			lv[lvcnt] = nd[i].lv;
			lvnd[lvcnt][0] = nd[i];
		}
		lvnd[lvcnt][1] = nd[i];
	}
	dp[1][0] = cal(nd[0], lvnd[1][1]) + cal(lvnd[1][1], lvnd[1][0]);
	dp[1][1] = cal(nd[0], lvnd[1][0]) + cal(lvnd[1][0], lvnd[1][1]);
	for(int i = 2 ; i <= lvcnt ; ++ i){
		dp[i][0] = min(
			dp[i-1][0] + cal(lvnd[i-1][0], lvnd[i][1]) + cal(lvnd[i][1], lvnd[i][0]),
			dp[i-1][1] + cal(lvnd[i-1][1], lvnd[i][1]) + cal(lvnd[i][1], lvnd[i][0])
		);
		dp[i][1] = min(
			dp[i-1][0] + cal(lvnd[i-1][0], lvnd[i][0]) + cal(lvnd[i][0], lvnd[i][1]),
			dp[i-1][1] + cal(lvnd[i-1][1], lvnd[i][0]) + cal(lvnd[i][0], lvnd[i][1])
		);
	}
	printf("%lld\n", min(dp[lvcnt][0], dp[lvcnt][1]));
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &nd[i].x, &nd[i].y);
	solve();
	return 0;
}

