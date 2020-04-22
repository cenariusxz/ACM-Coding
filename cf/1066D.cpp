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
ll a[maxn], sum[maxn];

void solve(){
	for(int i = n ; i >= 1 ; -- i)scanf("%lld", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	int pre = 0;
	for(int i = 1 ; i <= m ; ++ i){
		int l = pre + 1, r = n, ans = pre;
		while(l <= r){
			int mid = (l + r) / 2;
			if(sum[mid] - sum[pre] <= k)ans = max(ans, mid), l = mid + 1;
			else r = mid - 1;
		}
		pre = ans;
	}
	printf("%d\n", pre);
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	solve();
	return 0;
}

