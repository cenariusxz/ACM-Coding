#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 998244353;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

ll A[maxn], ans;
int n, deg[maxn];

void init(){
	A[1] = 1;
	for(int i = 2 ; i <= 200000 ; ++ i)A[i] = A[i-1] * i % mod;
}

int main(){
	init();
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		deg[a] ++;
		deg[b] ++;
	}
	ans = n;
	for(int i = 1 ; i <= n ; ++ i)ans = ans * A[deg[i]] % mod;
	printf("%lld\n", ans);
	return 0;
}

