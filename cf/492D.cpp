#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n, x, y;

void solve(){
	ll a;
	scanf("%lld", &a);
	a %= (x+y);
	ll l = 0, r = a * x, ans = INF;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(a <= mid/x + mid/y)ans = min(ans, mid), r = mid-1;
		else l = mid + 1;
	}
	if(ans % y == 0 && ans % x == 0)printf("Both\n");
	else if(ans % y == 0)printf("Vanya\n");
	else printf("Vova\n");
}

int main(){
	scanf("%d%d%d", &n, &x, &y);
	while(n--)solve();
	return 0;
}


