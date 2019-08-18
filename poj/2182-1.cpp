#include <stdio.h>
const int maxn = 1e5 + 5;
const int maxm = maxn<<2;

int st[maxm],n,ans[maxn],pre[maxn];

void build(int o,int l,int r){
	if(l == r){
		st[o] = 1;
		return;
	}
	int m = (l+r)>>1;
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o] = st[o<<1] + st[o<<1|1];
}

void update(int o,int l,int r,int ind){
	if(l == r){
		st[o] = 0;
		return;
	}
	int m = (l+r)>>1;
	if(ind <= m)update(o<<1,l,m,ind);
	else update(o<<1|1,m+1,r,ind);
	st[o] = st[o<<1] + st[o<<1|1];
}

int query(int o,int l,int r,int sum){
	if(l == r)return l;
	int m = (l+r)>>1;
	if(sum <= st[o<<1])return query(o<<1,l,m,sum);
	else return query(o<<1|1,m+1,r,sum-st[o<<1]);
}

int main(){
	scanf("%d",&n);
	build(1,1,n);
	for(int i = 2 ; i <= n ; ++ i)scanf("%d",&pre[i]);
	for(int i = n ; i >= 1 ; -- i){
		ans[i] = query(1,1,n,pre[i] + 1);
		update(1,1,n,ans[i]);
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%d\n",ans[i]);
	return 0;
}
