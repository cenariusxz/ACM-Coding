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

ll get(int n){
	ll ans = 1;
	for(int i = 1 ; i <= n ; ++ i)ans *= i;
	return ans;
}

void solve(int n){
	ll ans = get(n);
	for(int i = 1 ; i <= n ; ++ i){
		ll tmp = get(n) / get(n-i) / get(i) * get(n-i);
		if(i & 1)ans -= tmp;
		else ans += tmp;
	}
	printf("%lld\n", ans);
}

int main(){
	for(int i = 1 ; i <= 10 ; ++ i)solve(i);
	return 0;
}

