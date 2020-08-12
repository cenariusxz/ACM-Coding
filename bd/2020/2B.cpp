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

int n, a[maxn];
ll sum[maxn];

ll solve(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i)ans += sum[n] - sum[i] - (n - i) * (ll)a[i];
	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)printf("%lld\n", solve());
	return 0;
}

