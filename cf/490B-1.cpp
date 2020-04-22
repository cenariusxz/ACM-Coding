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

int n, fst[maxm], sec[maxm], nxt[maxm], ans[maxn];

void solve(){
	for(int i = 1 ; i <= n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		fst[a] = 1;
		sec[b] = 1;
		nxt[a] = b;
	}
	for(int i = 1 ; i <= 1000000 ; ++ i){
		if(fst[i] == 1 && sec[i] == 0)ans[1] = i;
	}
	ans[2] = nxt[0];
	for(int i = 3 ; i <= n ; ++ i)ans[i] = nxt[ans[i-2]];
	for(int i = 1 ; i <= n ; ++ i)printf("%d ", ans[i]);
	printf("\n");
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}

