#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
const int MAXM=50000;

int mi[(MAXM<<2)+5],ma[(MAXM<<2)+5],a[MAXM+5],a1,a2;

void build(int o,int l,int r){
	if(l==r){
		mi[o]=ma[o]=a[l];
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	mi[o]=min(mi[o<<1],mi[o<<1|1]);
	ma[o]=max(ma[o<<1],ma[o<<1|1]);
}
/*
int query1(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return ma[o];
	if(l==r)return ma[o];
	int m=l+((r-l)>>1),ans=0;
	if(ql<=m)ans=max(ans,query1(o<<1,l,m,ql,qr));
	if(qr>=m+1)ans=max(ans,query1(o<<1|1,m+1,r,ql,qr));
	return ans;
}

int query2(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return mi[o];
	if(l==r)return mi[o];
	int m=l+((r-l)>>1),ans=0x3f3f3f3f;
	if(ql<=m)ans=min(ans,query2(o<<1,l,m,ql,qr));
	if(qr>=m+1)ans=min(ans,query2(o<<1|1,m+1,r,ql,qr));
	return ans;
}
*/
void query(int o,int l,int r,int ql,int qr){
	if((ql<=l&&qr>=r)||(l==r)){
		a1=max(a1,ma[o]);
		a2=min(a2,mi[o]);
		return;
	}
	int m=l+((r-l)>>1);
	if(ql<=m)query(o<<1,l,m,ql,qr);
	if(qr>=m+1)query(o<<1|1,m+1,r,ql,qr);
	return;
}
int main(){
	int n,q,i;
	while(scanf("%d%d",&n,&q)!=EOF){
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		build(1,1,n);
		for(i=1;i<=q;i++){
			int a,b;a1=-1,a2=0x3f3f3f3f;
			scanf("%d%d",&a,&b);
			query(1,1,n,a,b);
			printf("%d\n",a1-a2);
		}
	}
	return 0;
}
