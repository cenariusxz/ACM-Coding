#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n, m, a[105], b[105], vis[105];

void solve(){
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(vis[j])continue;
			if(abs(a[i] -  b[j]) <= 1){
				ans ++;
				vis[j] = 1;
				break;
			}
		}
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i = 1 ; i <= m ; ++ i)scanf("%d", &b[i]);
	solve();
	return 0;
}


