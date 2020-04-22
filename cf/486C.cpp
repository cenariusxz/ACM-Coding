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

int n, p;
char s[maxn], vis[maxn];

void solve(){
	int ans = 0;
	for(int i = 1, j = n ; i < j ; ++ i, --j){
		if(s[i] != s[j]){
			vis[i] = 1;
			ans += min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
		}
		if(p == j)p = i;
	}
	if(ans == 0){
		printf("0\n");
		return;
	}
	int mn = INF, mx = 0;
	for(int i = 1 ; i <= n/2 ; ++ i){
		if(vis[i])mn = min(mn, i), mx = max(mx, i);
	}
	if(p < mn || p > mx)ans += max(abs(p - mn), abs(p-mx));
	else ans += mx - mn + min(p - mn, mx - p);
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d%s", &n, &p, s+1);
	solve();
	return 0;
}


