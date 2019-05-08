#include<stdio.h>
#include<string.h>
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxm=100005;

ll soo[(maxm<<2)+5],soe[(maxm<<2)+5],seo[(maxm<<2)+5],see[(maxm<<2)+5];
ll oo,oe,eo,ee;
int a[maxm+5];

inline ll max(ll a,ll b){
	return a>b?a:b;
}

void build(int o,int l,int r){
	if(l==r){
		if(l%2){
			soo[o]=a[l];
			soe[o]=seo[o]=see[o]=-INF;
		}
		else{
			see[o]=a[l];
			soo[o]=seo[o]=soe[o]=-INF;
		}
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	soo[o]=max(soe[o<<1]+soo[o<<1|1],max(soo[o<<1]+seo[o<<1|1],max(soo[o<<1],soo[o<<1|1])));
	soe[o]=max(soe[o<<1]+soe[o<<1|1],max(soo[o<<1]+see[o<<1|1],max(soe[o<<1],soe[o<<1|1])));
	seo[o]=max(seo[o<<1]+seo[o<<1|1],max(see[o<<1]+soo[o<<1|1],max(seo[o<<1],seo[o<<1|1])));
	see[o]=max(see[o<<1]+soe[o<<1|1],max(seo[o<<1]+see[o<<1|1],max(see[o<<1],see[o<<1|1])));
}

void update(int o,int l,int r,int a,int b){
	if(l==r){
		if(l%2){
			soo[o]=b;
			soe[o]=seo[o]=see[o]=-INF;
		}
		else{
			see[o]=b;
			soo[o]=seo[o]=soe[o]=-INF;
		}
		return;
	}
	int m=l+((r-l)>>1);
	if(a<=m)update(o<<1,l,m,a,b);
	else if(a>=m+1)update(o<<1|1,m+1,r,a,b);
	soo[o]=max(soe[o<<1]+soo[o<<1|1],max(soo[o<<1]+seo[o<<1|1],max(soo[o<<1],soo[o<<1|1])));
	soe[o]=max(soe[o<<1]+soe[o<<1|1],max(soo[o<<1]+see[o<<1|1],max(soe[o<<1],soe[o<<1|1])));
	seo[o]=max(seo[o<<1]+seo[o<<1|1],max(see[o<<1]+soo[o<<1|1],max(seo[o<<1],seo[o<<1|1])));
	see[o]=max(see[o<<1]+soe[o<<1|1],max(seo[o<<1]+see[o<<1|1],max(see[o<<1],see[o<<1|1])));
}

void query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		ll tmpoo,tmpoe,tmpeo,tmpee;
		tmpoo=max(oo,max(soo[o],max(oe+soo[o],oo+seo[o])));
		tmpoe=max(oe,max(soe[o],max(oe+soe[o],oo+see[o])));
		tmpeo=max(eo,max(seo[o],max(eo+seo[o],ee+soo[o])));
		tmpee=max(ee,max(see[o],max(ee+soe[o],eo+see[o])));
		oo=tmpoo;
		oe=tmpoe;
		eo=tmpeo;
		ee=tmpee;
		return;
	}
	int m=l+((r-l)>>1);
	if(ql<=m)query(o<<1,l,m,ql,qr);
	if(qr>=m+1)query(o<<1|1,m+1,r,ql,qr);
}

inline int read(){
	int x=0,d=1;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-'){
		d=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*d;
}

int main(){
	int T=read();
	while(T--){
		int n=read();
		int m=read();
		int i;
		for(i=1;i<=n;i++)a[i]=read();
		build(1,1,n);
		for(i=1;i<=m;i++){
			int num=read();
			int aa=read();
			int bb=read();
			if(num){
				update(1,1,n,aa,bb);
			}
			else{
				oo=oe=eo=ee=-INF;
				query(1,1,n,aa,bb);
				printf("%lld\n",max(oo,max(oe,max(eo,ee))));
			}
		}
	}
	return 0;
}
