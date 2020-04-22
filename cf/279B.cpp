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
// two-point

void solve(){
	int ans = 0, l = 1, sum = 0;
	for(int r = 1 ; r <= n ; ++ r){
		sum += a[r];
		while(sum > t)sum -= a[l++];
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d", &n, &t);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

