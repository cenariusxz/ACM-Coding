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

int n, t, a[maxn], sum[maxn];
// 前缀和枚举二分查找 

void solve(){
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int l = i - 1, r = n, res = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(sum[mid] - sum[i-1] <= t)res = max(res, mid), l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, res - i + 1);
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d", &n, &t);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

