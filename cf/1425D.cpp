#include <bits/stdc++.h>	//1425D
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, m, r, sum[1005][1005], x[2005], y[2005], num[2005];
ll C[2005][2005], b[2005];

void init(){
	for(int i = 0 ; i <= 2000 ; ++ i){
		for(int j = 0 ; j <= i ; ++ j){
			C[i][j]=(i==0||j==0)?1:(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	for(int i = 1 ; i <= n ; ++ i)sum[x[i]][y[i]] = 1;
	for(int i = 1 ; i <= 1000 ; ++ i){
		for(int j = 1 ; j <= 1000 ; ++ j)sum[i][j] += sum[i][j-1];
	}
	for(int i = 1 ; i <= 1000 ; ++ i){
		for(int j = 1 ; j <= 1000 ; ++ j)sum[i][j] += sum[i-1][j];
	}
}

bool check(int i, int j){
	return abs(x[i]-x[j]) <= r && abs(y[i]-y[j]) <= r;
}

int getnum(int i, int j){
	int x1 = max(max(x[i] - r, x[j] - r), 1);
	int x2 = min(min(x[i] + r, x[j] + r), 1000);
	int y1 = max(max(y[i] - r, y[j] - r), 1);
	int y2 = min(min(y[i] + r, y[j] + r), 1000);
	if(x1 > x2 || y1 > y2)return 0;
	return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}

int main(){
	scanf("%d%d%d", &n, &m, &r);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d%lld", &x[i], &y[i], &b[i]);
	init();
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int cnt = 0;
		for(int j = 1 ; j <= n ; ++ j)num[i] += check(i, j);
		ans = (ans + (C[n][m] - C[n-num[i]][m] + mod) % mod * b[i] % mod * b[i] % mod) % mod;
	}
	//printf("%lld\n", ans);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = i + 1 ; j <= n ; ++ j){
			int noti = n - num[i];
			int notj = n - num[j];
			int notij = n - num[i] - num[j] + getnum(i, j);
			//printf("%d\n", getnum(i, j));
			ans = (ans + (C[n][m] - C[noti][m] - C[notj][m] + C[notij][m] + mod + mod) % mod * b[i] % mod * b[j] % mod * 2) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

