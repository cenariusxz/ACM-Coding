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

ll sum[3][maxn], v[maxn];
int n, m;

void solve(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &v[i]);
	for(int i = 1 ; i <= n ; ++ i)sum[1][i] = sum[1][i-1] + v[i];
	sort(v + 1 , v + 1 + n);
	for(int i = 1 ; i <= n ; ++ i)sum[2][i] = sum[2][i-1] + v[i];
	scanf("%d", &m);
	while(m --){
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		printf("%lld\n", sum[t][r] - sum[t][l-1]);
	}
}

int main(){
	solve();
	return 0;
}

