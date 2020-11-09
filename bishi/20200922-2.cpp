#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

struct node{
	int a, b, v;
}nd[maxn];
int n, fa[maxn], num[maxn];

void init(){
	for(int i = 0 ; i <= n ; ++ i)num[i] = 1, fa[i] = i;
}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
bool cmp1(node x, node y){return x.v < y.v;}
bool cmp2(node x, node y){return x.v > y.v;}

void solve(){
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		scanf("%d%d%d", &nd[i].a, &nd[i].b, &nd[i].v);
	}
	ll ans = 0;
	init();
	sort(nd + 1, nd + n, cmp1);
	for(int i = 1 ; i < n ; ++ i){
		int x = find(nd[i].a), y = find(nd[i].b);
		ans += nd[i].v * (ll)num[x] * num[y];
		fa[x] = y;
		num[y] += num[x];
	}
	init();
	sort(nd + 1, nd + n, cmp2);
	for(int i = 1 ; i < n ; ++ i){
		int x = find(nd[i].a), y = find(nd[i].b);
		ans -= nd[i].v * (ll)num[x] * num[y];
		fa[x] = y;
		num[y] += num[x];
	}
	printf("%lld\n", ans);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

