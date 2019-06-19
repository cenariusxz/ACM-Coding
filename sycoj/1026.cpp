#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

ll a[maxn], d[maxn];
int n, k; 

int main(){
	scanf("%d%d",&n, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i < n ; ++ i)d[i] = a[i+1] - a[i];
	sort(d + 1 , d + n);
	ll ans = 0;
	for(int i = 1 ; i <= k ; ++ i)ans += d[i];
	printf("%lld\n",ans);
	return 0;
}


