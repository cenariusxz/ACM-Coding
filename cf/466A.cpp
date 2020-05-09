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

int n, m, a, b;

void solve(){
	int ans = INF;
	for(int i = 0 ; ; ++ i){
		int res1 = i * b;
		int res2 = (n - i * m) * a;
		if(res2 < 0)res2 = 0;
		ans = min(ans, res1 + res2);
		if(res2 == 0)break;
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d%d%d", &n, &m, &a, &b);
	solve();
	return 0;
}

