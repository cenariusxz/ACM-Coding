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

struct node{
	int l, r;
	bool operator < (const node x)const{
		return l < x.l;
	}
}nd[maxn];

int n;

void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &nd[i].l, &nd[i].r);
	sort(nd + 1, nd + 1 + n);
	int mx = 0, ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(mx > nd[i].r)ans ++;
		else mx = nd[i].r;
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}


