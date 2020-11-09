#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

int n, m;
int a[maxn], b[maxn];
ll c[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 0 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 0 ; i <= n ; ++ i)scanf("%d", &b[i]);
	for(int i = 0 ; i <= n ; ++ i){
		for(int j = 0 ; j <= n ; ++ j){
			c[i+j] += a[i] * (ll)b[j] % mod;
		}
	}
	for(int i = 0 ; i <= 2 * n ; ++ i)c[i] = (c[i] % mod + mod) % mod;
	scanf("%d", &m);
	while(m --){
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if(t == 1){
			ll ans = 0;
			for(int i = x ; i <= y ; ++ i)ans += c[i];
			printf("%lld\n", (ans % mod + mod) % mod);
		}
		else{
			for(int i = 0 ; i <= n ; ++ i){
				c[x+i] += y * (ll)b[i];
				c[x+i] = (c[x+i] % mod + mod) % mod;
			}
		}
	}
	return 0;
}

