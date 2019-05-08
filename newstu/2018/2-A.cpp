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

int a[maxn];

ll ans = 0;

int main(){
	int n;
	while(scanf("%d",&n) && n){
		int ans = 0;
		for(int i = 1 ; i <= n ; ++ i){
			scanf("%d",&a[i]);
		}
		sort(a + 1 , a + n + 1, greater<int>());
		for(int i = 1 ; i <= n ; ++ i){
			ans += i * a[i];
		}
		ans -= a[n];
		printf("%d\n",ans);
	}
	return 0;
}
