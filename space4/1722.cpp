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

ll a[maxn];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	while(m --){
		int x, y;
		scanf("%d%d", &x, &y);
		a[x] ++;
		a[y] ++;
	}
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i)ans += a[i] * (n-1 - a[i]);
	printf("%lld\n", n * (ll)(n-1) * (n-2) / 6 - ans / 2);
	return 0;
}

