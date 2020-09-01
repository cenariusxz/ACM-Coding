#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int n, m, a[maxn], st[maxn], ed[maxn];
int lt[maxn], rt[maxn];

int main(){
	scanf("%d%d", &m, &n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d", &a[i]);
		if(st[a[i]] == 0)st[a[i]] = i;
		ed[a[i]] = i;
	}
	int pos = 0;
	for(int i = 1 ; i <= m ; ++ i){	// l 取 i , 左区间占据范围 
		if(ed[i-1] == 0)lt[i] = pos;
		else if(st[i-1] <= pos)lt[i] = pos = INF;
		else lt[i] = pos = ed[i-1];
	}
	pos = n+1;
	for(int i = m ; i >= 1 ; -- i){	// r 取 i , 右区间占据范围 
		if(ed[i+1] == 0)rt[i] = pos;
		else if(ed[i+1] >= pos)rt[i] = pos = -1;
		else rt[i] = pos = st[i+1];
	}
	ll ans = 0;
	pos = 1;
	for(int i = 1 ; i <= m ; ++ i){
		while(pos <= m && rt[pos] <= lt[i])pos ++;
		if(rt[pos] > lt[i])ans += m - pos + 1;
	}
	printf("%lld\n", ans);
	return 0;
}

