#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
const int maxm = 1e6 + 6;

int n, m, a[2][maxn], vis[maxn];

ll solve(int t, int l, int r, int c){
	t --;
	for(int i = l ; i <= r ; ++ i)vis[i] = 1;
	ll ans = 0;
	for(int i = l ; i <= r ; ++ i)ans += max(a[0][i], a[1][i]);
	ll tmp = c;
	for(int i = l ; i <= r ; ++ i)tmp += a[t][i];
	return ans > tmp ? ans : tmp;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[0][i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[1][i]);
	ll ans = 0;
	while(m --){
		int t, l, r, c;
		scanf("%d%d%d%d", &t, &l, &r, &c);
		ans += solve(t, l, r, c);
	}
	for(int i = 1 ; i <= n ; ++ i)if(!vis[i])ans += max(a[0][i], a[1][i]);
	printf("%lld\n", ans);
	return 0;
}

