#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 998244353;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, m;
char s[maxn], t[maxn];

void solve(){
	for(int i = 1, j = n ; i < j ; ++ i, -- j)swap(s[i], s[j]);
	for(int i = 1, j = m ; i < j ; ++ i, -- j)swap(t[i], t[j]);
	ll ans = 0, num = 0, pow2 = 1;
	for(int i = 1 ; i <= m ; ++ i){
		if(i <= n){
			if(s[i] == '1')num = (num + pow2) % mod;
			pow2 = (pow2 + pow2) % mod;
		}
		if(t[i] == '1')ans = (ans + num) % mod;
	}
	printf("%lld\n", ans);
}

int main(){
	scanf("%d%d%s%s", &n, &m, s+1, t+1);
	solve();
	return 0;
}

