#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 5;

int n,m;
int a[maxm];
int dp[2][maxn];

bool solve(){
	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		int now = i & 1;
		int pre = now ^ 1;
		for(int j = 0 ; j < m ; ++ j){
			// dp[i-1][j];
			if(dp[pre][j] == 0)continue;
			dp[now][j] = 1;
			int x = j + a[i];
			// printf("%d %d %d\n",j , a[i], x);
			if(x % m == 0)return 1;
			x %= m;
			dp[now][x] = 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d", &a[i]);
		if(a[i] % m == 0){
			printf("YES\n");
			return 0;
		}
		a[i] %= m;
	}
	if(solve())printf("YES\n");
	else printf("NO\n");
	return 0;
}

