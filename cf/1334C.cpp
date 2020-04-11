#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 3e6 + 5;

ll a[maxm], b[maxm], del[maxm];
int n;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1 ; i <= n ; ++ i)scanf("%lld%lld", &a[i], &b[i]);
		for(int i = 1 ; i <= n ; ++ i){
			int pos = i+1;
			if(pos == n+1)pos = 1;
			del[pos] = a[pos] - b[i];
			if(del[pos] < 0)del[pos] = 0;
		}
		ll sum = 0;
		for(int i = 1 ; i <= n ; ++ i)sum += del[i];
		ll ans = INF;
		for(int i = 1 ; i <= n ; ++ i){
			ans = min(ans, a[i] + sum - del[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

