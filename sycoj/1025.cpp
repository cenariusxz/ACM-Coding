#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int main(){
	ll x, y;
	int ans = 0;
	scanf("%lld%lld", &x, &y);
	for(ll p = x; p <= y ; p += x){
		if(x * y % p != 0)continue;
		ll q = x * y / p;
		if(__gcd(p, q) == x)ans++;
	}
	printf("%d\n", ans);
	return 0;
}


