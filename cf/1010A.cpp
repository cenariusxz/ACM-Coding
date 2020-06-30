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

int n, m;
int a[maxn], b[maxn];

bool check(double mid){
	double wt = m + mid, cost = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int from = i, to = i == n ? 1 : i + 1;
		double c = wt / a[from];
		cost += c; wt -= c;
		if(cost > mid)return 0;
		c = wt / b[to];
		cost += c; wt -= c;
		if(cost > mid)return 0;
	}
	return 1;
}

void solve(){
	double l = 0, r = 1e9, ans = 1e9;
	for(int i = 1 ; i <= 65 ; ++ i){
		double mid = (l + r) / 2;
		if(check(mid))ans = min(ans, mid), r = mid;
		else l = mid;
	}
	if(fabs(ans - 1e9) < eps)printf("-1\n");
	else printf("%.10lf\n", ans);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &b[i]);
	solve();
	return 0;
}

