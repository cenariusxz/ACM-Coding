#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n, r;
int a[1005];

void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	int pre = 0, ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(i <= pre)continue;
		int last = -1;
		for(int j = max(1, i - r + 1) ; j <= min(n, i + r - 1) ; ++ j){
			if(a[j] == 1)last = j;
		}
		if(last == -1){
			printf("-1\n");
			return;
		}
		ans ++;
		pre = last + r - 1;
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d", &n, &r);
	solve();
	return 0;
}
