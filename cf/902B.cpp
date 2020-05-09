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

int n;
int p[maxn], c[maxn];

void solve(){
	int ans = n;
	for(int i = 2 ; i <= n ; ++ i)ans -= (c[i] == c[p[i]]);
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 2 ; i <= n ; ++ i)scanf("%d", &p[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &c[i]);
	solve();
	return 0;
}

