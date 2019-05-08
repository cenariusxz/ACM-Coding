#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxm=100005;

int st[(maxm<<2)+5],a[maxm];

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

int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		return st[o];
	}
	int m=l+((r-l)>>1);
	int ans=0;
	if(ql<=m)ans=max(ans,query(o<<1,l,m,ql,qr));
	if(qr>=m+1)ans=max(ans,query(o<<1|1,m+1,r,ql,qr));
	return ans;
}

int main(){
	int T=read();
	while(T--){
		int n=read();
		int i;
		for(i=1;i<=n;i++)a[i]=read();
		build(1,1,n);

	}
	return 0;
}
