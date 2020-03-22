#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e3 + 5;

int n,m;
int a[maxn], dp[2][maxm];

bool solve(){
	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		int now = i & 1;
		int pre = now ^ 1;
		for(int j = 0 ; j < m ; ++ j){
			if(!dp[pre][j])continue;
			dp[now][j] = 1;
			int x = j + a[i];
			if(x == m)return 1;
			if(x > m)x -= m;
			dp[now][x] = 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d", &a[i]);
		a[i] %= m;
		if(a[i] == 0){
			printf("YES\n");
			return 0;
		}
	}
	if(solve())printf("YES\n");
	else printf("NO\n");
	return 0;
}

