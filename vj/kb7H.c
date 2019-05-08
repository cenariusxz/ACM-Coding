#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define ll long long
const int MAXM=100000;

ll a[MAXM+5],segtree[(MAXM<<2)+5];
ll lazy[(MAXM<<2)+5];

void build(ll o,ll l,ll r){
	if(l==r){
		if(a[l]==1) lazy[o]=1;
		segtree[o]=a[l];
		return;
	}
	ll m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	lazy[o]=lazy[o<<1]&&lazy[o<<1|1];
	segtree[o]=segtree[o<<1]+segtree[o<<1|1];
}

ll query(ll o,ll l,ll r,ll ql,ll qr){
	if(ql<=l&&qr>=r){
		return segtree[o];
	}
	ll m=l+((r-l)>>1),tmp=0;
	if  (ql<=m) tmp+=query(o<<1,l,m,ql,qr);
	if  (qr>m) tmp+=query(o<<1|1,m+1,r,ql,qr);
	return tmp;
}

void pushup(ll o){
	lazy[o]=lazy[o<<1]&&lazy[o<<1|1];
	segtree[o]=segtree[o<<1]+segtree[o<<1|1];
}

void update(ll o,ll l,ll r,ll ql,ll qr){
	if(lazy[o])return;
	if(l==r){
		segtree[o]=(ll)sqrt(segtree[o]*1.0);
		if(segtree[o]==1)lazy[o]=1;
		return;
	}
	ll m=l+((r-l)>>1);
	if (ql<=m) update(o<<1,l,m,ql,qr);
	if (qr>m) update(o<<1|1,m+1,r,ql,qr);
	pushup(o);
}

int main(){
	ll n,c=0;
	while(scanf("%I64d",&n)!=EOF){
		printf("Case #%I64d:\n",++c);
		ll i;
		for(i=1;i<=n;i++){
			scanf("%I64d",&a[i]);
		}
		memset(segtree,0,sizeof(segtree));
		memset(lazy,0,sizeof(lazy));
		build(1,1,n);
		ll m;
		scanf("%I64d",&m);
		for(i=1;i<=m;i++){
			ll f,x,y;
			scanf("%I64d%I64d%I64d",&f,&x,&y);
			if (x>y) swap(x,y);
			if(f) printf("%I64d\n",query(1,1,n,x,y));
			else update(1,1,n,x,y);
		}
		printf("\n");
	}
	return 0;
}
