#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

int st[maxn<<2],add[maxn<<2];
int a[maxn];

void build(){
	for(int i=1;i<=2e5+1;++i)st[i]=-INF;
	memset(add,0,sizeof(add));
}

void pushdown(int o,int l,int r){
	if(add[o]){
		add[o<<1]+=add[o];
		add[o<<1|1]+=add[o];
		st[o<<1]+=add[o];
		st[o<<1|1]+=add[o];
		add[o]=0;
	}
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		st[o]+=c;
		add[o]+=c;
		return;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
	st[o]=max(st[o<<1],st[o<<1|1]);
}

int num=0;

int query(int o,int l,int r,int c){
	if(l==r){
		num=st[o];
		return l;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(c<=st[o<<1]){
		return query(o<<1,l,m,c);
	}
	else{
		return query(o<<1|1,m+1,r,c);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		build();
		int ans=0;
		int l=1,r=2*n;
		int ql=n+1,qr=n+1;
		if(a[1])update(1,l,r,n+1,n+1,INF+a[1]);
		for(int i=2;i<=n;++i){
			if(a[i]==0){
				update(1,l,r,ql,qr,1);
				ql--;
			}
			else{
				if(a[i]>st[1]){
					update(1,l,r,qr+1,qr+1,INF+a[i]);
					qr++;
				}
				else{
					int pos=query(1,l,r,a[i]);
					update(1,l,r,pos,pos,a[i]-num);
				}
			}
		}
		printf("Case #%d: %d\n",q,qr-ql+1);
	}
	return 0;
}
