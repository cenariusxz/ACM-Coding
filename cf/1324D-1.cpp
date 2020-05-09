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

int n, a[maxn], b[maxn], c[maxn];

void solve(){
	for(int i = 1 ; i <= n ; ++ i)c[i] = a[i] - b[i];
	sort(c + 1 , c + 1 + n , greater<int>() );
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(c[i] <= 0)continue;
		int l = 1, r = n, res = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(c[i] + c[mid] > 0)res = max(res, mid), l = mid + 1;
			else r = mid - 1;
		}
		if(res > i)ans += res - i;
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &b[i]);
	solve();
	return 0;
}
