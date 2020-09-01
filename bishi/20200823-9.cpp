#include <bits/stdc++.h>
using namespace std;
#define MP make_pair		// modify
#define PB push_back		// modify
typedef long long ll;
const int m1 = 1e9 + 7;		// modify
const int m2 = 1e9 + 9;		// modify
const int b1 = 100019;		// modify
const int b2 = 100043;		// modify
const int maxn = 2e5 + 5;

int n, m;
vector<int> V[maxn];
map<pair<ll, ll>, int>M;	// modify

int main(){
	scanf("%d%d", &n, &m);
	while(m --){
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	for(int i = 1 ; i <= n ; ++ i)sort(V[i].begin(), V[i].end());
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		ll h1 = 0, h2 = 0;		// modify
		for(int j = 0 ; j < V[i].size() ; ++ j){
			h1 = (h1 * b1 + V[i][j]) % m1;		// modify
			h2 = (h2 * b2 + V[i][j]) % m2;		// modify
		}
		ans += M[MP(h1, h2)];		// modify
		M[MP(h1, h2)] ++;			// modify
	}
	printf("%lld\n", ans);
	return 0;
}

