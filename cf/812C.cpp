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

int n, S;
int a[maxn], ans;
ll v[maxn], cost;

bool check(int mid){
	for(int i = 1 ; i <= n ; ++ i)v[i] = a[i] + mid * (ll)i;
	sort(v + 1 , v + 1 + n);
	ll sum = 0;
	for(int i = 1 ; i <= mid ; ++ i)sum += v[i];
	if(sum <= S){
		if(ans < mid)ans = mid, cost = sum;
		return 1;
	}
	return 0;
}

void solve(){
	int l = 1, r = n;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid))l = mid + 1;
		else r = mid - 1;
	}
	printf("%d %lld\n", ans, cost);
}

int main(){
	scanf("%d%d", &n, &S);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

