#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;

int st[maxn<<2],add[maxn<<2];
int a[maxn];
int tmp[maxn];

void build(int o,int l,int r){
	add[o]=0;
	if(l==r){
		st[o]=tmp[l];
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o]=max(st[o<<1],st[o<<1|1]);
}

void pushdown(int o){
	if(add[o]){
		st[o<<1]+=add[o];
		add[o<<1]+=add[o];
		st[o<<1|1]+=add[o];
		add[o<<1|1]+=add[o];
		add[o]=0;
	}
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		st[o]+=c;
		add[o]+=c;
		return;
	}
	pushdown(o);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
	st[o]=max(st[o<<1],st[o<<1|1]);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return st[o];
	pushdown(o);
	int m=l+((r-l)>>1);
	int ans=-INF;
	if(ql<=m)ans=max(ans,query(o<<1,l,m,ql,qr));
	if(qr>=m+1)ans=max(ans,query(o<<1|1,m+1,r,ql,qr));
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			tmp[i]=a[i]-i+1;
		}
		build(1,1,n);
		int ans=-INF;
		for(int i=1;i<=n;++i){
			int res=-INF;
			if(i!=1)res=max(res,query(1,1,n,1,i-1));
			if(i!=n)res=max(res,query(1,1,n,i+1,n));
			ans=max(ans,res+a[i]);
			update(1,1,n,1,i,-1);
			if(i!=n)update(1,1,n,i+1,n,1);
		}
		printf("%d\n",-ans);
	}
	return 0;
}
