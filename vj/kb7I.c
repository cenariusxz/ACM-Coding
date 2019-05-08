#include<stdio.h>
#include<string.h>
const int MAXM=50000;

int d[MAXM+5];
int ql[(MAXM<<2)+5],qr[(MAXM<<2)+5],qs[(MAXM<<2)+5];

void build(int o,int l,int r){
	if(l!=r){
		int m=l+((r-l)>>1);
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
	ql[o]=qr[o]=qs[o]=r-l+1;
	return;
}

int Max(int x,int y){
	return x>y?x:y;
}

void update(int o,int l,int r,int ind,bool f){
	if(l==r){
		if(f)ql[o]=qr[o]=qs[o]=0;
		else ql[o]=qr[o]=qs[o]=1;
		return;
	}
	int m=l+((r-l)>>1);
	if(ind<=m)update(o<<1,l,m,ind,f);
	else update(o<<1|1,m+1,r,ind,f);
	ql[o]=ql[o<<1];
	qr[o]=qr[o<<1|1];
	if(ql[o<<1]==m-l+1)ql[o]+=ql[o<<1|1];
	if(qr[o<<1|1]==r-m)qr[o]+=qr[o<<1];
	qs[o]=Max(Max(qs[o<<1],qs[o<<1|1]),qr[o<<1]+ql[o<<1|1]);
	return;
}

int query(int o,int l,int r,int b){
	if(l==r||qs[o]==0||qs[o]==r-l+1)return qs[o];
	int m=l+((r-l)>>1);
	if(b<=m){
		if(b>=m-qr[o<<1]+1)return query(o<<1,l,m,b)+query(o<<1|1,m+1,r,m+1);
		else return query(o<<1,l,m,b);
	}
	else{
		if(b<=m+ql[o<<1|1])return query(o<<1|1,m+1,r,b)+query(o<<1,l,m,m);
		else return query(o<<1|1,m+1,r,b);
	}
/*	if(b>=r-qr[o]+1)return qr[o];
	else if(b<=l+ql[o]-1)return ql[o];
	else return query(o<<1,l,m,b)+query(o<<1|1,m+1,r,b);*/
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		char a[10];
		int cnt=0;
		build(1,1,n);
		for(int i=1;i<=m;i++){
			scanf("%s",a);
			if(a[0]=='D'){
				scanf("%d",&d[++cnt]);
				update(1,1,n,d[cnt],1);
			}
			else if(a[0]=='R'){
				update(1,1,n,d[cnt--],0);
			}
			else if(a[0]=='Q'){
				int b;
				scanf("%d",&b);
				printf("%d\n",query(1,1,n,b));
			}
		}
	}
	return 0;
}
