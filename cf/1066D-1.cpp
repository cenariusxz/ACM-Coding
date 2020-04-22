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

int n, m, k;
ll a[maxn];

bool check(int num){
	ll sum = 0;
	int box = 1;
	for(int i = n - num + 1 ; i <= n ; ++ i){
		if(sum + a[i] <= k)sum += a[i];
		else sum = a[i], box++;
	}
	return box <= m;
}

void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	int l = 1, r = n, ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid))ans = max(ans, mid), l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	solve();
	return 0;
}

