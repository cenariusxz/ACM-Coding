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

int n, q;
ll a[maxn], k[maxn], sum[maxn];

void solve(){
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	ll num = 0;
	for(int i = 1 ; i <= q ; ++ i){
		num += k[i];
		int l = 0, r = n, ans = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(sum[mid] <= num)ans = max(ans, mid), l = mid + 1;
			else r = mid - 1;
		}
		if(ans == n)ans = 0, num = 0;
		printf("%d\n", n - ans);
	}
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	for(int i = 1 ; i <= q ; ++ i)scanf("%lld", &k[i]);
	solve();
	return 0;
}

