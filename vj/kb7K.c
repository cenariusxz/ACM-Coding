#include<stdio.h>
#include<string.h>
#define ll long long
const ll MAXM=100000;
const ll mod=10007;

ll a[MAXM+5],add[(MAXM<<2)+5],change[(MAXM<<2)+5],mul[(MAXM<<2)+5];

void pushdown(int o,int l,int r){
	int m=l+((r-l)>>1);
	if(add[o]){
		if(l==m)a[l]+=add[o];
		else add[o<<1]+=add[o];
		if(m+1==r)a[r]+=add[o];
		else add[o<<1|1]+=add[o];
		add[o]=0;
	}
	if(change[o]){
		if(l==m)a[l]=change[o];
		else change[o<<1]=change[o];
		if(m+1==r)a[r]=change[o];
		else change[o<<1|1]=change[o];
		change[o]=0;
	}
	if(mul[o]!=1){
		if(l==m)a[l]*=mul[o];
		else mul[o<<1]*=mul[o];
		if(m+1==r)a[r]*=mul[o];
		else mul[o<<1|1]*=mul[o];
		mul[o]=1;
	}
}

void update1(int o,int l,int r,ll ql,ll qr,ll b){
	if(l==r){
		a[l]+=b;
		return;
	}
	if(ql<=l&&qr>=r){
		add[o]+=b;
		return;
	}
	int m=l+((r-l)>>1);
	pushdown(o,l,r);
	
}


int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0||m!=0){
		for(int i=1;i<=m;i++){
			int f;
			ll x,y,b;
			memset(a,0,sizeof(a));
			memset(add,0,sizeof(add));
			memset(change,0,sizeof(change));
			memset(mul,0,sizeof(mul));
			scanf("%d%lld%lld%lld",&f,&x,&y,&b);
			if(f==1){
				update1(1,1,n,x,y,b);
			}
			if(f==2){

			}
			if(f==3){

			}
			if(f==4){

			}
		}
	}
	return 0;
}
