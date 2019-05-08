#include<stdio.h>
#include<string.h>

const int MAXM=50000;

int a[MAXM+5],segtree[MAXM*4+5];

void build(int o,int l,int r){
	if(l==r)segtree[o]=a[l];
	else{
		int m=l+((r-l)>>1);
		build(o<<1,l,m);
		build((o<<1)+1,m+1,r);
		segtree[o]=segtree[o<<1]+segtree[(o<<1)+1];
	}
}

int query(int o,int l,int r,int ql,int qr){
	if(ql>r||qr<l) return 0;
	if(l>=ql&&r<=qr) return segtree[o];
	int m=l+((r-l)>>1);
	int p1=query(o<<1,l,m,ql,qr),p2=query((o<<1)+1,m+1,r,ql,qr);
	return p1+p2;
}

void update(int o,int l,int r,int ind,int add){
	if(l==r){
		segtree[o]+=add;
		return;
	}
	int m=l+((r-l)>>1);
	if(ind<=m){
		update((o<<1),l,m,ind,add);
	}
	else{
		update((o<<1)+1,m+1,r,ind,add);
	}
	segtree[o]=segtree[o<<1]+segtree[(o<<1)+1];
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			printf("Case %d:\n",q);
			memset(segtree,0,sizeof(segtree));
			int n;
			scanf("%d",&n);
			int i;
			for(i=1;i<=n;i++){
				scanf("%d",&a[i]);
			}
			build(1,1,n);
			char s[10];
			while(scanf("%s",s)){
				int a,b;
				if(s[0]=='Q'){
					scanf("%d%d",&a,&b);
					printf("%d\n",query(1,1,n,a,b));
				}
				else if(s[0]=='A'){
					scanf("%d%d",&a,&b);
					update(1,1,n,a,b);
				}
				else if(s[0]=='S'){
					scanf("%d%d",&a,&b);
					update(1,1,n,a,-b);
				}
				else if(s[0]=='E'){
					break;
				}
			}
		}
	}
	return 0;
}
