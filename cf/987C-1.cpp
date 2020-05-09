#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 3005;
const int maxm = 1e6 + 5;

int n, s[maxn], c[maxn];

ll min(ll a, ll b){return a < b ? a : b;}

void solve(){
	ll ans = INF;
	for(int j = 1 ; j <= n ; ++ j){
		ll resi = INF, resj = c[j], resk = INF;
		for(int i = 1 ; i < j ; ++ i){
			if(s[i] >= s[j])continue;
			resi = min(resi, c[i]);
		}
		for(int k = j+1 ; k <= n ; ++ k){
			if(s[j] >= s[k])continue;
			resk = min(resk, c[k]);
		}
		ans = min(ans, resi + resj + resk);
	}
	if(ans == INF)ans = -1;
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &s[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &c[i]);
	solve();
	return 0;
}

