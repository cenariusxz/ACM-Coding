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

int n, t[maxn];

void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &t[i]);
	sort(t + 1, t + 1 + n);
	ll sum = 0;
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(sum <= t[i])sum += t[i], ans++;
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}

