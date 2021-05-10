#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, a, b, n;

ll cal(int i){
	ll sum = x + (n-i) * b;
	ll times = sum / a + 1;
	ll t = times <= i ? times : i;
	ll tmp = (2*sum - (t-1) * a) * t / 2;
	return tmp;
}

void solve(){
	scanf("%lld%lld%lld%lld", &x, &a, &b, &n);
	int l = 1, r = n;
	while(l <= r){
		int mid = (l+r) >> 1;
		int midmid = (mid+r) >> 1;
		if(cal(mid) > cal(midmid)) r = midmid-1;
		else l = mid+1;
	}
	printf("%d %lld %d %lld\n", l, cal(l), r, cal(r));
	printf("%lld\n", cal(r+1));
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

