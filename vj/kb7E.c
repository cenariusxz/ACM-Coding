#include<stdio.h>
#include<string.h>

const int MAXM=100000;

int segtree[(MAXM<<2)+5],change[(MAXM<<2)+5];

void build(int o,int l,int r){
	if(l==r){
		segtree[o]=1;
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
	if(change[o]){
		int c=change[o];
		change[o<<1]=c;
		change[o<<1|1]=c;
		int m=l+((r-l)>>1);
		segtree[o<<1]=(m-l+1)*c;
		segtree[o<<1|1]=(r-m)*c;
		change[o]=0;
	}
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql==l&&qr==r){
		change[o]=c;
		segtree[o]=(r-l+1)*c;
		return;
	}
	if(l==r)return;
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(qr<=m){
		update(o<<1,l,m,ql,qr,c);
	}
	else if(ql>=m+1){
		update(o<<1|1,m+1,r,ql,qr,c);
	}
	else{
		update(o<<1,l,m,ql,m,c);
		update(o<<1|1,m+1,r,m+1,qr,c);
	}
	pushup(o);
}

int query(int o,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return segtree[o];
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	int ans=0;
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
	int T;
	int n,Q;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			scanf("%d%d",&n,&Q);
			memset(segtree,0,sizeof(segtree));
			memset(change,0,sizeof(change));
			build(1,1,n);
			int i;
			for(i=1;i<=Q;i++){
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				update(1,1,n,a,b,c);
			}
			printf("Case %d: The total value of the hook is %d.\n",q,query(1,1,n,1,n));
		}
	}
	return 0;
}
