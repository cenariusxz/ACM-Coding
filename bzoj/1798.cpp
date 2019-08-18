#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = maxn<<2;

ll st[maxm],mul[maxm],add[maxm];
int num[maxn],mod,n;

void build(int o,int l,int r){
	add[o] = 0;
	mul[o] = 1;
	if(l == r){
		st[o] = num[l]%mod;
		return;
	}
	int m = (l+r) >> 1;
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o] = (st[o<<1] + st[o<<1|1]) % mod;
}

void pushdown(int o,int l,int r){
	int m = (l+r) >> 1;
	if(add[o] || mul[o] != 1){
		mul[o<<1] = mul[o<<1] * mul[o] % mod;
		add[o<<1] = (add[o<<1] * mul[o] % mod + add[o]) % mod;
		st[o<<1] = (st[o<<1] * mul[o] % mod + add[o] * (m-l+1) % mod) % mod;
		mul[o<<1|1] = mul[o<<1|1] * mul[o] % mod;
		add[o<<1|1] = (add[o<<1|1] * mul[o] % mod + add[o]) % mod;
		st[o<<1|1] = (st[o<<1|1] * mul[o] % mod + add[o] * (r-m) % mod) % mod;
		add[o] = 0;
		mul[o] = 1;
	}
}

void updateadd(int o,int l,int r,int ql,int qr,ll c){
	if(ql <= l && qr >= r){
		add[o] = (add[o] + c) % mod;
		st[o] = (st[o] + c * (r-l+1) % mod) % mod;
		return;
	}
	pushdown(o,l,r);
	int m = (l+r) >> 1;
	if(ql <= m)updateadd(o<<1,l,m,ql,qr,c);
	if(qr >= m+1)updateadd(o<<1|1,m+1,r,ql,qr,c);
	st[o] = (st[o<<1] + st[o<<1|1]) % mod;
}

void updatemul(int o,int l,int r,int ql,int qr,ll c){
	if(ql <= l && qr >= r){
		mul[o] = mul[o] * c % mod;
		add[o] = add[o] * c % mod;
		st[o] = st[o] * c % mod;
		return;
	}
	pushdown(o,l,r);
	int m = (l+r) >> 1;
	if(ql <= m)updatemul(o<<1,l,m,ql,qr,c);
	if(qr >= m+1)updatemul(o<<1|1,m+1,r,ql,qr,c);
	st[o] = (st[o<<1] + st[o<<1|1]) % mod;
}

ll query(int o,int l,int r,int ql,int qr){
	if(ql <= l && qr >= r)return st[o];
	pushdown(o,l,r);
	int m = (l+r) >> 1;
	ll ans = 0;
	if(ql <= m)ans = (ans + query(o<<1,l,m,ql,qr)) % mod;
	if(qr >= m+1)ans = (ans + query(o<<1|1,m+1,r,ql,qr)) % mod;
	return ans;
}

int main(){
	scanf("%d%d",&n,&mod);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	while(m--){
		int type;
		scanf("%d",&type);
		if(type == 1){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			c %= mod;
			updatemul(1,1,n,l,r,c);	
		}
		if(type == 2){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			c %= mod;
			updateadd(1,1,n,l,r,c);	
		}
		if(type == 3){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,1,n,l,r));	
		}
	}
	return 0;
}

