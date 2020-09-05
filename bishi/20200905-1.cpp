#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

ll a[5]; 

bool check(ll x){
	ll need = 0, more = 0;
	for(int i = 1 ; i <= 3 ; ++ i){
		if(a[i] < x)need += x - a[i];
		else more += a[i] - x;
	}
	return more >= 2 * need;
}

int main(){
	scanf("%lld,%lld,%lld", &a[1], &a[2], &a[3]);
	ll l = 0, r = INF, ans = 0;
	while(l <= r){
		ll m = (l + r) >> 1;
		if(check(m))l = m + 1, ans = max((int)ans, (int)m);
		else r = m - 1;
	}
	printf("%lld\n", ans);
	return 0;
}

