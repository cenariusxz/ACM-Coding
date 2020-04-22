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

int n;
int pre[maxm], nxt[maxm];
int ans[maxn];

void solve(){
	memset(pre, -1, sizeof(pre));
	memset(nxt, -1, sizeof(nxt));
	for(int i = 1 ; i <= n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		nxt[a] = b;
		pre[b] = a;
	}
	for(int i = 1 ; i <= 1000000 ; ++ i){
		if(nxt[i] != -1 && pre[i] == -1)ans[1] = i;
	}
	for(int i = 2 ; i <= n ; ++ i){
		ans[i] = nxt[ans[i-2]];
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%d ", ans[i]);
	printf("\n");
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}


