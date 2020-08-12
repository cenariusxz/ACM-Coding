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

int n, a[maxn]; 

void solve(){
	sort(a + 1, a + 1 + n);
	int ans = 1;
	int pos = 0;
	for(int i = 1 ; i <= n ; ++ i){
		while(pos < n && a[pos+1] <= a[i] + 5)pos ++;
		ans = max(ans, pos - i + 1);
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

