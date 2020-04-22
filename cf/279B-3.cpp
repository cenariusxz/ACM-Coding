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
//二分答案前缀和 

bool check(int len){
	for(int i = 1 ; i + len - 1 <= n ; ++ i){
		if(sum[i + len - 1] - sum[i-1] <= t)return 1;
	}
	return 0;
}

void solve(){
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	int l = 1, r = n, ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid))ans = max(ans, mid), l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d", &n, &t);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

