#include <stdio.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, ans;
int a[10][10];

inline int max(int a, int b){return a > b ? a : b;}
inline int min(int a, int b){return a < b ? a : b;}

int cal(){
	int res = 0;
	for(int j = 1 ; j <= n ; ++ j){
		int sum = 0;
		for(int i = 1 ; i <= n ; ++ i)sum += a[i][j];
		res = max(res, sum);
	}
	return res;
}

void shift(int i){
	for(int j = n ; j >= 1 ; -- j)a[i][j+1] = a[i][j];
	a[i][1] = a[i][n+1];
}

void dfs(int t){
	if(t == n){
		ans = min(ans, cal());
		return;
	}
	for(int i = 1 ; i <= n ; ++ i){
		shift(t+1);
		dfs(t+1);
	}
}

void solve(){
	ans = INF;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			scanf("%d", &a[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", ans);
}

int main(){
	while(scanf("%d", &n) && ~n)solve();
	return 0;
}

