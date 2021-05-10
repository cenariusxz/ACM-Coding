#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, a, b, n;

ll max(ll a, ll b){return a > b ? a : b;}

ll cal(int i){
	ll sum = x + (n-i) * b;
	ll times = sum / a + 1;
	ll t = times <= i ? times : i;
	ll tmp = (2*sum - (t-1) * a) * t / 2;
	return tmp;
}

void solve(){
	scanf("%lld%lld%lld%lld", &x, &a, &b, &n);
	ll ans = 0;
	int l = 1, r = n;
	while(l <= r){
		int mid = (l+r) >> 1;
		int midmid = (mid+r) >> 1;
		if(mid == midmid){
			for(int i = l ; i <= r ; ++ i)ans = max(ans, cal(i));
			break;
		}
		if(cal(mid) > cal(midmid)) r = midmid-1, ans = max(ans, cal(mid));
		else l = mid+1, ans = max(ans, cal(midmid));
	}
	printf("%lld\n", ans);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

