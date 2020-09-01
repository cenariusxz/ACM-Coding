#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
const int mod = 1e8 + 7;
const int maxn = 1e5 + 5;

int n, num[maxn << 2], sum[maxn << 2], add[maxn << 2];
vector<int> V[maxn];

void pushup(int o){
	num[o] = num[o << 1] + num[o << 1 | 1];
	sum[o] = (sum[o << 1] + sum[o << 1 | 1]) % mod;
}

void pushdown(int o){
	if(add[o]){
		add[o << 1] += add[o];
		add[o << 1 | 1] += add[o];
		sum[o << 1] += add[o] * (ll)num[o << 1] % mod;
		sum[o << 1] %= mod;
		sum[o << 1 | 1] += add[o] * (ll)num[o << 1 | 1] % mod;
		sum[o << 1 | 1] %= mod;
		add[o] = 0;
	}
}

int query(int o, int l, int r, int ql, int qr){
	if(ql <= l && qr >= r)return sum[o];
	pushdown(o);
	int m = (l + r) >> 1;
	int ans = 0;
	if(ql <= m)ans += query(o<<1, l, m, ql, qr);
	if(qr >= m + 1)ans += query(o<<1|1, m+1, r, ql, qr);
	return ans % mod;
}

void upd1(int o, int l, int r, int ql, int qr){
	if(ql <= l && qr >= r){
		add[o] ++;
		sum[o] += num[o];
		return;
	}
	pushdown(o);
	int m = (l + r) >> 1;
	if(ql <= m)upd1(o<<1, l, m, ql, qr);
	if(qr >= m + 1)upd1(o<<1|1, m+1, r, ql, qr);
	pushup(o);
}

void upd2(int o, int l, int r, int ind){
	if(l == r){
		num[o] ++;
		return;
	}
	pushdown(o);
	int m = (l + r) >> 1;
	if(ind <= m)upd2(o<<1, l, m, ind);
	else upd2(o<<1|1, m+1, r, ind);
	pushup(o);
}

void solve(){
	int ans = 0;
	for(int val = 100000 ; val >= 0 ; -- val){
		for(int i = 0 ; i < V[val].size() ; ++ i){
			ans += query(1, 0, n+1, V[val][i] + 1, n+1);
			ans %= mod;
		}
		for(int i = 0 ; i < V[val].size() ; ++ i){
			upd1(1, 0, n+1, 0, V[val][i] - 1);
		}
		for(int i = 0 ; i < V[val].size() ; ++ i){
			upd2(1, 0, n+1, V[val][i]);
		}
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d", &a);
		V[abs(a)].PB(i);
	}
	solve();
	return 0;
}

