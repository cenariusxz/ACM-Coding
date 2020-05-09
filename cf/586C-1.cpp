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

int n, vis[maxn];
ll v[maxn], d[maxn], p[maxn];

void solve(){
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		ans ++;
		ll del1 = v[i], del2 = 0;
		for(int j = i + 1 ; j <= n ; ++ j){
			if(vis[j])continue;
			p[j] -= del1 + del2;
			if(del1)del1 --;
			if(p[j] < 0)vis[j] = 1, del2 += d[j];
		}
	}
	printf("%d\n", ans);
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		printf("%d ", i);
	}
	printf("\n");
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d%d", &v[i], &d[i], &p[i]);
	solve();
	return 0;
}

