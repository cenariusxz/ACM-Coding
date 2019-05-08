#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxm=10000;

int segtree[(maxm<<2)+5],add[(maxm<<2)+5],a[maxm];

void build(int o,int l,int r){
	if(l==r)segtree[o]=a[l];
	else{
		int m=l+((r-l)>>1);
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		segtree[o]=max(segtree[o<<1],segtree[o<<1|1]);
	}
}

void pushup(int o){
	segtree[o]=max(segtree[o<<1],segtree[o<<1|1]);
}

void pushdown(int o,int l,int r){
	if(add[o]){
		add[o<<1]+=add[o];
		add[o<<1|1]+=add[o];
		segtree[o<<1]+=add[o];
		segtree[o<<1|1]+=add[o];
		add[o]=0;
	}
}

void update(int o,int l,int r,int ql,int qr,int addv){
	if(ql<=l&&qr>=r){
		add[o]+=addv;
		segtree[o]+=addv;
		return;
	}
	pushdown(o,l,r);

	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,addv);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,addv);
	pushup(o);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return segtree[o];
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	int ans=-0x3f3f3f3f;
	if(ql<=m)ans=max(query(o<<1,l,m,ql,qr),ans);
	if(qr>=m+1)ans=max(query(o<<1|1,m+1,r,ql,qr),ans);
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(1){
		int a;
		scanf("%d",&a);
		if(a==1){
			int l,r,addv;
			scanf("%d%d%d",&l,&r,&addv);
			update(1,1,n,l,r,addv);
		}
		else if(a==2){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,1,n,l,r));
		}
		else if(a==0){
			for(int i=1;i<=n;i++){
				printf("%d ",query(1,1,n,i,i));	
			}
			printf("\n");
		}
	}
	return 0;
}
