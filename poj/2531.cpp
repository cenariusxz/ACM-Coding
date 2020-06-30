#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, ans;
int C[25][25];
int vis[25];

void dfs(int t){
	if(t == n){
		int res = 0;
		for(int i = 1 ; i <= n ; ++ i){
			for(int j = i + 1 ; j <= n ; ++ j){
				res += (vis[i] == vis[j]) ? 0 : C[i][j];
			}
		}
		ans = max(ans, res);
		return;
	}
	dfs(t + 1);
	vis[t+1] = 1;
	dfs(t + 1);
	vis[t+1] = 0;
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			scanf("%d", &C[i][j]);
		}
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}

