#include<stdio.h>
#include<string.h>
const int maxm=50005;

char s[10];
int a[maxm],st[maxm<<2];

void build(int o,int l,int r){
	if(l==r){
		st[o]=a[l];
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o]=st[o<<1]+st[o<<1|1];
}

void update(int o,int l,int r,int x,int c){
	if(l==r){
		st[o]+=c;
		return;
	}
	int m=l+((r-l)>>1);
	if(x<=m)update(o<<1,l,m,x,c);
	if(x>=m+1)update(o<<1|1,m+1,r,x,c);
	st[o]=st[o<<1]+st[o<<1|1];
}

int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return st[o];
	int m=l+((r-l)>>1);
	int ans=0;
	if(ql<=m)ans+=query(o<<1,l,m,ql,qr);
	if(qr>=m+1)ans+=query(o<<1|1,m+1,r,ql,qr);
	return ans;
}

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


int main(){
	int T=read();
	for(int q=1;q<=T;q++){
		int n=read();
		int i;
		for(i=1;i<=n;i++)a[i]=read();
		build(1,1,n);
		printf("Case %d:\n",q);
		while(1){
			scanf("%s",s);
			if(s[0]=='Q'){
				int ql=read();
				int qr=read();
				printf("%d\n",query(1,1,n,ql,qr));
			}
			else if(s[0]=='A'){
				int x=read();
				int c=read();
				update(1,1,n,x,c);
			}
			else if(s[0]=='S'){
				int x=read();
				int c=read();
				update(1,1,n,x,-c);
			}
			else if(s[0]=='E')break;
		}
	}
	return 0;
}
