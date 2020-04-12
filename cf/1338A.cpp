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

int n, a[maxn], del[maxn];

void solve(){
	int mx = a[1];
	int ans = 0;
	for(int i = 2 ; i <= n ; ++ i){
		if(a[i] > mx)mx = a[i];
		else ans = max(ans, mx - a[i]);
	}
	int t = 0;
	while(ans){
		t++;
		ans /= 2;
	}
	printf("%d\n", t);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
		solve();
	}
	return 0;
}


