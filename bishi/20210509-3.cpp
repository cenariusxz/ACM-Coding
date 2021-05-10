#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, a, b, n;

void solve(){
	scanf("%lld%lld%lld%lld", &x, &a, &b, &n);
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		ll sum = x + (n-i) * b;
		ll times = sum / a + 1;
		ll t = times <= i ? times : i;
		ll tmp = (2*sum - (t-1) * a) * t / 2;
		printf("%d: %lld %lld %lld %lld xxx %lld\n", i, sum, times, t, tmp, sum - (t-1)*a);
		if(tmp > ans)ans = tmp;
	}
	printf("%lld\n", ans);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

