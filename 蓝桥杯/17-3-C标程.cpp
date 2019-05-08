#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;

int st[maxn<<2][10],laz[maxn<<2][10];
int a[maxn];

void build(int o,int l,int r){
	if(l==r){
		st[o][a[l]]=1;
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	for(int i=0;i<=9;++i){
		st[o][i]=st[o<<1][i]+st[o<<1|1][i];
	}
}

void pushdown(int o,int l,int r,int x){
	if(laz[o][x]!=-1){
		int c=laz[o][x];
		int m=l+((r-l)>>1);
		st[o<<1][x]=(m-l+1)*c;
		st[o<<1|1][x]=(r-m)*c;
		laz[o<<1][x]=laz[o<<1|1][x]=c;
		laz[o][x]=-1;
	}
}

int query1(int o,int l,int r,int k,int x){
	if(l==r){
		if(k==st[o][x])return l;
		else return -1;
	}
	pushdown(o,l,r,x);
	if(st[o][x]<k)return -1;
	int m=l+((r-l)>>1);
	if(st[o<<1][x]>=k)return query1(o<<1,l,m,k,x);
	else return query1(o<<1|1,m+1,r,k-st[o<<1][x],x);
}

int query2(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l&&qr>=r){
		return st[o][x];
	}
	pushdown(o,l,r,x);
	int m=l+((r-l)>>1);
	int ans=0;
	if(ql<=m)ans+=query2(o<<1,l,m,ql,qr,x);
	if(qr>=m+1)ans+=query2(o<<1|1,m+1,r,ql,qr,x);
	return ans;
}

void update(int o,int l,int r,int ql,int qr,int x,int c){
	if(ql<=l&&qr>=r){
		laz[o][x]=c;
		st[o][x]=(r-l+1)*c;
		return;
	}
	pushdown(o,l,r,c);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,x,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,x,c);
	st[o][x]=st[o<<1][x]+st[o<<1|1][x];
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(st,0,sizeof(st));
		memset(laz,-1,sizeof(laz));
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		build(1,1,n);
		while(q--){
			int t;
			scanf("%d",&t);
			if(t==1){
				int x,y,a;
				scanf("%d%d%d",&x,&y,&a);
				int p1=query1(1,1,n,a,x);
				int p2=query1(1,1,n,a,y);
				if(p1==-1||p2==-1)printf("-1\r\n");
				else printf("%d\r\n",max(p1,p2));
			}
			else if(t==2){
				int a,b;
				scanf("%d%d",&a,&b);
				int Max=-1,p=0;
				for(int i=0;i<=9;++i){
					int num=query2(1,1,n,a,b,i);
					if(num>Max)Max=num,p=i;
				}
				printf("%d\r\n",p);
				for(int i=0;i<=9;++i){
					if(i==p)update(1,1,n,a,b,i,1);
					else update(1,1,n,a,b,i,0);
				}
			}
		}
	}
	return 0;
}
