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

int n, t, a[maxn];
//¶þ·Ö´ð°¸two-point 

bool check(int len){
	int sum = 0;
	for(int i = 1 ; i <= n ; ++ i){
		sum += a[i];
		if(i >= len && sum <= t)return 1;
		if(i >= len)sum -= a[i - len + 1];
	}
	return 0;
}

void solve(){
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

