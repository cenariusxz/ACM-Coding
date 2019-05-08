#include<stdio.h>
#include<string.h>
const int maxm=50006;
const int INF=0x3f3f3f3f;

int st[maxm<<2],ma[maxm<<2],mi[maxm<<2];
int ch[maxm<<2];
int maxx,minn,k;

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

void build(int o,int l,int r){
	ma[o]=r;
	mi[o]=l;
	st[o]=r-l+1;
	ch[o]=0;
	if(l==r)return;
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
}

void pushdown(int o,int l,int r){
	if(ch[o]==1){
		ch[o<<1]=ch[o<<1|1]=1;
		int m=l+((r-l)>>1);
		st[o<<1]=st[o<<1|1]=0;
		ma[o<<1]=ma[o<<1|1]=-1;
		mi[o<<1]=mi[o<<1|1]=INF;
		ch[o]=0;
	}
	else if(ch[o]==2){
		ch[o<<1]=ch[o<<1|1]=2;
		int m=l+((r-l)>>1);
		st[o<<1]=m-l+1;
		st[o<<1|1]=r-m;
		ma[o<<1]=m;
		ma[o<<1|1]=r;
		mi[o<<1]=l;
		mi[o<<1|1]=m+1;
		ch[o]=0;
	}
}

void update1(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		if(k>=st[o]){
			k-=st[o];
			maxx=max(maxx,ma[o]);
			minn=min(minn,mi[o]);
			ma[o]=-1;
			mi[o]=INF;
			st[o]=0;
			ch[o]=1;
			return;
		}
		else if(l==r)return;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m&&k)update1(o<<1,l,m,ql,qr);
	if(qr>=m+1&&k)update1(o<<1|1,m+1,r,ql,qr);
	ma[o]=max(ma[o<<1],ma[o<<1|1]);
	mi[o]=min(mi[o<<1],mi[o<<1|1]);
	st[o]=st[o<<1]+st[o<<1|1];
}

int update2(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		int ans=r-l+1-st[o];
		st[o]=r-l+1;
		ma[o]=r;
		mi[o]=l;
		ch[o]=2;
		return ans;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	int ans=0;
	if(ql<=m)ans+=update2(o<<1,l,m,ql,qr);
	if(qr>=m+1)ans+=update2(o<<1|1,m+1,r,ql,qr);
	ma[o]=max(ma[o<<1],ma[o<<1|1]);
	mi[o]=min(mi[o<<1],mi[o<<1|1]);
	st[o]=st[o<<1]+st[o<<1|1];
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		build(1,0,n-1);
		for(int i=1;i<=m;++i){
			int t;
			scanf("%d",&t);
			if(t==1){
				int a;
				scanf("%d%d",&a,&k);
				maxx=-1;
				minn=INF;
				update1(1,0,n-1,a,n-1);
				if(maxx==-1&&minn==INF)printf("Can not put any one.\n");
				else printf("%d %d\n",minn,maxx);
			}
			else if(t==2){
				int a,b;
				scanf("%d%d",&a,&b);
				printf("%d\n",update2(1,0,n-1,a,b));
			}
		}
		printf("\n");
	}
	return 0;
}
