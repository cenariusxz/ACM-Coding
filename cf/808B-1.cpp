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

int n, k;
ll a[maxn], sum[maxn];

void solve(){
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	for(int i = 1 ; i + k - 1 <= n ; ++ i){
		int l = i, r = i + k - 1;
		ans += sum[r] - sum[l-1];
	}
	printf("%.10lf\n", ans * 1.0 / (n-k+1));
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	solve();
	return 0;
}

