#include<stdio.h>
#include<string.h>
#define ll long long
const int MAXM=100000;

ll segtree[MAXM*4+5],add[MAXM*4+5];
int a[MAXM+5];

void build(int o,int l,int r){
	if(l==r){
		segtree[o]=a[l];
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	segtree[o]=segtree[o<<1]+segtree[o<<1|1];
}

void pushup(int o){
	segtree[o]=segtree[o<<1]+segtree[o<<1|1];
}

void pushdown(int o,int l,int r){
	if(add[o]){
		add[o<<1]+=add[o];
		add[o<<1|1]+=add[o];
		int m=l+((r-l)>>1);
		segtree[o<<1]+=add[o]*(m-l+1);
		segtree[o<<1|1]+=add[o]*(r-m);
		add[o]=0;
	}
}

void update(int o,int l,int r,int ql,int qr,int addv){
	if(l==ql&&r==qr){
		add[o]+=addv;
		segtree[o]+=addv*(r-l+1);
		return;
	}
	if(l==r)return;
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(qr<=m){
		update(o<<1,l,m,ql,qr,addv);
	}
	else if(ql>=m+1){
		update(o<<1|1,m+1,r,ql,qr,addv);
	}
	else{
		update(o<<1,l,m,ql,m,addv);
		update(o<<1|1,m+1,r,m+1,qr,addv);
	}
	pushup(o);
}

ll query(int o,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return segtree[o];
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	ll ans=0;
	if(qr<=m){
		ans+=query(o<<1,l,m,ql,qr);
	}
	else if(ql>=m+1){
		ans+=query(o<<1|1,m+1,r,ql,qr);
	}
	else{
		ans+=query(o<<1,l,m,ql,m);
		ans+=query(o<<1|1,m+1,r,m+1,qr);
	}
	return ans;
}

int main(){
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF){
		memset(segtree,0,sizeof(segtree));
		memset(add,0,sizeof(add));
		int i;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		build(1,1,n);
		char s[10];
		for(i=1;i<=q;i++){
			scanf("%s",s);
			if(s[0]=='Q'){
				int a,b;
				scanf("%d%d",&a,&b);
				printf("%I64d\n",query(1,1,n,a,b));
				
			}
			else if(s[0]=='C'){
				int a,b,m;
				scanf("%d%d%d",&a,&b,&m);
				update(1,1,n,a,b,m);
			}
		}
	}
	return 0;
}
