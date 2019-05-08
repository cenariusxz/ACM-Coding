#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;

int st[maxn<<2];
int ans[maxn];
int num=0;

void build(){
	st[1]=2;
}

void pushdown(int o,int l,int r){
	if(st[o]){
		int m=l+((r-l)>>1);
		st[o<<1]=st[o];
		st[o<<1|1]=st[o];
		st[o]=0;
	}
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		st[o]=c;
		return;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
}

void query(int o,int l,int r,int ql,int qr){
	int m=l+((r-l)>>1);
	if(st[o]){
		ans[++num]=st[o];
		return;
	}
	pushdown(o,l,r);
	if(ql<=m)query(o<<1,l,m,ql,qr);
	if(qr>=m+1)query(o<<1|1,m+1,r,ql,qr);
}

char s[10];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		build();
		while(m--){
			scanf("%s",s);
			if(s[0]=='P'){
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				update(1,1,n,a,b,c);
			}
			else{
				int a,b;
				scanf("%d%d",&a,&b);
				num=0;
				query(1,1,n,a,b);
				sort(ans+1,ans+num+1);
				int t=unique(ans+1,ans+num+1)-ans-1;
				for(int i=1;i<=t;++i){
					printf("%d",ans[i]);
					if(i==t)printf("\n");
					else printf(" ");
				}
			}
		}
	}
	return 0;
}
