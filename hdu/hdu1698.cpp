#include<stdio.h>
#include<string.h>
const int maxm=100005;
int st[maxm<<2],cha[maxm<<2];

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void build(int o,int l,int r){
	if(l==r){st[o]=1;return;}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o]=st[o<<1]+st[o<<1|1];
}

void pushup(int o){
	st[o]=st[o<<1]+st[o<<1|1];
}

void pushdown(int o,int l,int r){
	if(cha[o]){
		cha[o<<1]=cha[o];
		cha[o<<1|1]=cha[o];
		int m=l+((r-l)>>1);
		st[o<<1]=cha[o]*(m-l+1);
		st[o<<1|1]=cha[o]*(r-m);
		cha[o]=0;
	}
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		cha[o]=c;
		st[o]=c*(r-l+1);
		return;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
	pushup(o);
}

int main(){
	int T=read();
	for(int q=1;q<=T;q++){
		memset(cha,0,sizeof(cha));
		int n=read();
		build(1,1,n);
		int m=read();
		for(int i=1;i<=m;i++){
			int ql=read();
			int qr=read();
			int c=read();
			update(1,1,n,ql,qr,c);
		}
		printf("Case %d: The total value of the hook is %d.\n",q,st[1]);
	}
	return 0;
}
