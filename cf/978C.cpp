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

int n, m;
ll a[maxn], b[maxn], sum[maxn];

void solve(){
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	for(int i = 1 ; i <= m ; ++ i){
		int l = 1, r = n, ans = INF;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(sum[mid] >= b[i])ans = min(ans, mid), r = mid - 1;
			else l = mid + 1;
		}
		printf("%d %lld\n", ans, b[i] - sum[ans-1]);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	for(int i = 1 ; i <= m ; ++ i)scanf("%lld", &b[i]);
	solve();
	return 0;
}

