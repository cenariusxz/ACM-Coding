#include<stdio.h>
#include<string.h>
const int maxm=1000000*4;
int st[maxm+5],add[maxm+5];

int mmax(int a,int b){
	return a>b?a:b;
}

void pushup(int o){
	st[o]=mmax(st[o<<1],st[o<<1|1]);
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

void update(int o,int l,int r,int ql,int qr,int a){
	if(ql<=l&&qr>=r){
		add[o]+=a;
		st[o]+=a;
		return;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,a);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,a);
	pushup(o);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return st[o];
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	int tmp=0;
	if(ql<=m)tmp=mmax(tmp,query(o<<1,l,m,ql,qr));
	if(qr>=m+1)tmp=mmax(tmp,query(o<<1|1,m+1,r,ql,qr));
	return tmp;
}

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int w=1;w<=t;w++){
			printf("Case %d:\n",w);
			memset(st,0,sizeof(st));
			memset(add,0,sizeof(add));
			int k,q,ans=0,m=0;
			scanf("%d%d",&k,&q);
			for(int i=1;i<=q;i++){
				int a,b;
				scanf("%d%d",&a,&b);
				b--;
				if(query(1,1,1000000,a,b)<k){
					update(1,1,1000000,a,b,1);
					ans++;
					printf("%d ",i);
				}
			}
			printf("\n\n");
		}
	}
	return 0;
}
