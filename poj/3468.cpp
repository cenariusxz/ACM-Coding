#include<stdio.h>
#include<string.h>
typedef long long ll;
const int maxm=100005;

ll a[maxm],add[maxm<<2],st[maxm<<2];
char s[10];

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

void build(int o,int l,int r){
	if(l==r){st[o]=a[l];return;}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o]=st[o<<1]+st[o<<1|1];
}

void pushdown(int o,int l,int r){
	if(add[o]){
		add[o<<1]+=add[o];
		add[o<<1|1]+=add[o];
		int m=l+((r-l)>>1);
		st[o<<1]+=(m-l+1)*add[o];
		st[o<<1|1]+=(r-m)*add[o];
		add[o]=0;
	}
}

void pushup(int o){
	st[o]=st[o<<1]+st[o<<1|1];
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		add[o]+=c;
		st[o]+=(r-l+1)*c;
		return;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
	pushup(o);
}

ll query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		return st[o];
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	ll ans=0;
	if(ql<=m)ans+=query(o<<1,l,m,ql,qr);
	if(qr>=m+1)ans+=query(o<<1|1,m+1,r,ql,qr);
	return ans;
}

int main(){
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF){
		int i;
		for(i=1;i<=n;i++)a[i]=read();
		memset(add,0,sizeof(add));
		build(1,1,n);
		for(i=1;i<=q;i++){
			scanf("%s",s);
			if(s[0]=='Q'){
				int ql=read();
				int qr=read();
				printf("%lld\n",query(1,1,n,ql,qr));
			}
			else if(s[0]=='C'){
				int ql=read();
				int qr=read();
				int c=read();
				update(1,1,n,ql,qr,c);
			}
		}
	}
	return 0;
}
