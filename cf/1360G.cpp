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

int ans[55][55];

void solve(){
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	if(n * a != m * b){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	memset(ans, 0, sizeof(ans));
	int pos = 0;
	for(int i = 1 ; i <= n ; ++ i){		
		for(int j = 1 ; j <= a ; ++ j){
			ans[i][pos] = 1;
			pos++;
			pos %= m;
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 0 ; j < m ; ++ j){
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

