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

int n,a[maxn],vis[maxn];

void solve(){
	memset(vis, 0, (n+2) * sizeof(int));
	for(int i = 0 ; i < n ; ++ i){
		vis[((i + a[i]) % n + n) % n] ++;
	}
	for(int i = 0 ; i < n ; ++ i){
		if(vis[i] != 1){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
		a[0] = a[n];
		solve();
	}
	return 0;
}

