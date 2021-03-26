#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[205];
int n = 0;

ll min(ll x, ll y){return x < y ? x : y;}

bool check(ll mid){
	for(int i = 1 ; i <= n ; ++ i){
		ll num = min(a[i] * 2, mid / 2);
		if(i == n)num = mid;
		if(num < a[i])return 0;
		mid -= num;
	}
	return 1;
}

int main(){
	ll x;
	while(scanf("%lld", &x) != EOF)a[++n] = x;
	// n = 3;
	// for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	ll sum = 0;
	for(int i = 1 ; i <= n ; ++ i)sum += a[i];
	ll l = sum, r = sum * 2, ans = sum * 2;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(check(mid))r = mid - 1, ans = min(ans, mid);
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}

