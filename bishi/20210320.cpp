#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

int n, m, C, a[maxn];

bool check(ll mid){
	int sum = INF, cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		sum += a[i];
		if(sum > mid * C){
			cnt ++;
			sum = a[i];
		}
	}
	return cnt <= m;
}

int main(){
	scanf("%d%d%d", &n, &m, &C);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	int sum = 0;
	for(int i = 1 ; i <= n ; ++ i)sum += a[i];
	ll l = 1, r = sum / C + 1, ans = INF;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(check(mid))r = mid - 1, ans = min(ans, mid);
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}

