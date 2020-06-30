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

int n, k, q;
int sum[maxn], cnt[maxn], ans[maxn]; 

void solve(){
	for(int i = 1 ; i <= n ; ++ i){
		int l, r;
		scanf("%d%d", &l, &r);
		sum[l] ++;
		sum[r+1] --;
	}
	for(int i = 1 ; i <= 200000 ; ++ i)sum[i] += sum[i-1];
	for(int i = 1 ; i <= 200000 ; ++ i)sum[i] = sum[i] >= k;
	for(int i = 1 ; i <= 200000 ; ++ i)sum[i] += sum[i-1];
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", sum[r] - sum[l-1]);
	}
}

int main(){
	scanf("%d%d%d", &n, &k, &q);
	solve();
	return 0;
}

