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

ll num[5];

inline ll max(ll a, ll b){return a > b ? a : b;}

bool check(ll x){
	ll need = 0, more = 0;
	for(int i = 1 ; i <= 4 ; ++ i){
		if(num[i] < x)need += x - num[i];
		else more += num[i] - x;
	}
	return more >= need * 2;
}

int main(){
	for(int i = 1 ; i <= 4 ; ++ i)scanf("%lld", &num[i]);
	ll l = 1, r = 1e17 + 5, ans = 0;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid))l = mid + 1, ans = max(ans, mid);
		else r = mid - 1;
	}
	printf("%lld\n", ans * 4);
	return 0;
}

