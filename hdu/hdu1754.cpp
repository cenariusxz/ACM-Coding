#include<stdio.h>
const int maxm=200005;

int a[maxm],st[maxm<<2];
char s[10];

int max(int a,int b){
	return a>b?a:b;
}

void build(int o,int l,int r){
	if(l==r){
		st[o]=a[l];
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o]=max(st[o<<1],st[o<<1|1]);
}

void update(int o,int l,int r,int x,int c){
	if(l==r){
		st[o]=c;
		return;
	}
	int m=l+((r-l)>>1);
	if(x<=m)update(o<<1,l,m,x,c);
	if(x>=m+1)update(o<<1|1,m+1,r,x,c);
	st[o]=max(st[o<<1],st[o<<1|1]);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return st[o];
	int m=l+((r-l)>>1);
	int maxx=-0x3f3f3f3f;
	if(ql<=m)maxx=max(maxx,query(o<<1,l,m,ql,qr));
	if(qr>=m+1)maxx=max(maxx,query(o<<1|1,m+1,r,ql,qr));
	return maxx;
}

int read(){
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
	return d*x;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int i;
		for(i=1;i<=n;i++)a[i]=read();
		build(1,1,n);
		for(i=1;i<=m;i++){
			scanf("%s",s);
			if(s[0]=='Q'){
				int ql=read();
				int qr=read();
				printf("%d\n",query(1,1,n,ql,qr));
			}
			else if(s[0]=='U'){
				int x=read();
				int c=read();
				update(1,1,n,x,c);
			}
		}
	}
	return 0;
}
