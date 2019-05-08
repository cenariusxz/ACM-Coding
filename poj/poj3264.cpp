#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxm=500005;
const int INF=0x3f3f3f3f;

int ma[maxm<<1],mi[maxm<<1],a[maxm];
int maxx,minn,ql,qr;

int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a<b?a:b;
}

void build(int o,int l,int r){
	if(l==r){
		ma[o]=mi[o]=a[l];
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	ma[o]=max(ma[o<<1],ma[o<<1|1]);
	mi[o]=min(mi[o<<1],mi[o<<1|1]);
}

void query(int o,int l,int r){
	if(ql<=l&&qr>=r){
		maxx=max(maxx,ma[o]);
		minn=min(minn,mi[o]);
		return;
	}
	int m=l+((r-l)>>1);
	if(ql<=m)query(o<<1,l,m);
	if(qr>m)query(o<<1|1,m+1,r);
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
	int n=read();
	int m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;++i){
		ql=read();
		qr=read();
		maxx=0;
		minn=INF;
		query(1,1,n);
		printf("%d\n",maxx-minn);
	}
	return 0;
}
