#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
const int MAXM=200000;

int a[MAXM+5],segtree[MAXM*4+5];

void build(int o,int l,int r){
	if(l==r){
		segtree[o]=a[l];
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build((o<<1)+1,m+1,r);
	segtree[o]=max(segtree[o<<1],segtree[(o<<1)+1]);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql>r||qr<l) return -1;
	if(ql<=l&&qr>=r) return segtree[o];
	int m=l+((r-l)>>1);
	int p1=query(o<<1,l,m,ql,qr),p2=query((o<<1)+1,m+1,r,ql,qr);
	return max(p1,p2);
}

void update(int o,int l,int r,int ind,int ans){
	if(l==r){
		segtree[o]=ans;
		return;
	}
	int m=l+((r-l)>>1);
	if(ind<=m){
		update(o<<1,l,m,ind,ans);
	}
	else{
		update((o<<1)+1,m+1,r,ind,ans);
	}
	segtree[o]=max(segtree[o<<1],segtree[(o<<1)+1]);
}

int main(){
	int m,n;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(segtree,0,sizeof(segtree));
		int i;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		build(1,1,n);
		char s[10];
		for(i=1;i<=m;i++){
			int a,b;
			scanf("%s%d%d",s,&a,&b);
			if(s[0]=='Q'){
				printf("%d\n",query(1,1,n,a,b));
			}
			else if(s[0]=='U'){
				update(1,1,n,a,b);	
			}
		}
	}
	return 0;
}
