#include<stdio.h>
#include<string.h>
const int mod=10007;
const int maxm=100005;

int st[4][maxm<<2],add[maxm<<2],mul[maxm<<2],cha[maxm<<2];

void build(int o,int l,int r){
	st[1][o]=st[2][o]=st[3][o]=0;
	add[o]=cha[o]=0;
	mul[o]=1;
	if(l==r)return;
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
}

void pushdown(int o,int l,int r){
	if(cha[o]){
		cha[o<<1]=cha[o<<1|1]=cha[o];
		add[o<<1]=add[o<<1|1]=0;
		mul[o<<1]=mul[o<<1|1]=1;
		int m=l+((r-l)>>1);
		st[1][o<<1]=cha[o]*(m-l+1)%mod;
		st[1][o<<1|1]=cha[o]*(r-m)%mod;
		st[2][o<<1]=(cha[o]*cha[o]%mod)*(m-l+1)%mod;
		st[2][o<<1|1]=(cha[o]*cha[o]%mod)*(r-m)%mod;
		st[3][o<<1]=((cha[o]*cha[o]%mod)*cha[o]%mod)*(m-l+1)%mod;
		st[3][o<<1|1]=((cha[o]*cha[o]%mod)*cha[o]%mod)*(r-m)%mod;
		cha[o]=0;
	}
	if(add[o]||(mul[o]!=1)){
		int m=l+((r-l)>>1);
		add[o<<1]=(add[o<<1]*mul[o]%mod+add[o])%mod;
		mul[o<<1]=mul[o<<1]*mul[o]%mod;
		st[3][o<<1]=(
				((st[3][o<<1]*mul[o]%mod)*mul[o]%mod)*mul[o]%mod 
				+(((st[2][o<<1]*mul[o]%mod)*mul[o]%mod)*add[o]%mod)*3%mod
				+(((st[1][o<<1]*mul[o]%mod)*add[o]%mod)*add[o]%mod)*3%mod
				+((add[o]*add[o]%mod)*add[o]%mod)*(m-l+1)%mod
				)%mod;
		st[2][o<<1]=(
				(st[2][o<<1]*mul[o]%mod)*mul[o]%mod
				+((st[1][o<<1]*mul[o]%mod)*add[o]%mod)*2%mod
				+(add[o]*add[o]%mod)*(m-l+1)%mod
				)%mod;
		st[1][o<<1]=(
				st[1][o<<1]*mul[o]%mod+add[o]*(m-l+1)%mod
				)%mod;
		add[o<<1|1]=(add[o<<1|1]*mul[o]%mod+add[o])%mod;
		mul[o<<1|1]=mul[o<<1|1]*mul[o]%mod;
		st[3][o<<1|1]=(
				((st[3][o<<1|1]*mul[o]%mod)*mul[o]%mod)*mul[o]%mod 
				+(((st[2][o<<1|1]*mul[o]%mod)*mul[o]%mod)*add[o]%mod)*3%mod
				+(((st[1][o<<1|1]*mul[o]%mod)*add[o]%mod)*add[o]%mod)*3%mod
				+((add[o]*add[o]%mod)*add[o]%mod)*(r-m)%mod
				)%mod;
		st[2][o<<1|1]=(
				(st[2][o<<1|1]*mul[o]%mod)*mul[o]%mod
				+((st[1][o<<1|1]*mul[o]%mod)*add[o]%mod)*2%mod
				+(add[o]*add[o]%mod)*(r-m)%mod
				)%mod;
		st[1][o<<1|1]=(
				st[1][o<<1|1]*mul[o]%mod+add[o]*(r-m)%mod
				)%mod;
		add[o]=0;
		mul[o]=1;
	}
}

void update3(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		st[1][o]=c*(r-l+1)%mod;
		st[2][o]=(c*c%mod)*(r-l+1)%mod;
		st[3][o]=((c*c%mod)*c%mod)*(r-l+1)%mod;
		cha[o]=c;
		add[o]=0;
		mul[o]=1;
		return;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m)update3(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update3(o<<1|1,m+1,r,ql,qr,c);
	st[1][o]=(st[1][o<<1]+st[1][o<<1|1])%mod;
	st[2][o]=(st[2][o<<1]+st[2][o<<1|1])%mod;
	st[3][o]=(st[3][o<<1]+st[3][o<<1|1])%mod;
}

void update1(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		add[o]=(add[o]+c)%mod;
		st[3][o]=(st[3][o]+(c*st[2][o]%mod)*3%mod+((st[1][o]*c%mod)*c%mod)*3%mod+((c*c%mod)*c%mod)*(r-l+1)%mod)%mod;
		st[2][o]=(st[2][o]+(c*st[1][o]%mod)*2%mod+(c*c%mod)*(r-l+1)%mod)%mod;
		st[1][o]=(st[1][o]+c*(r-l+1)%mod)%mod;
		return;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m)update1(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update1(o<<1|1,m+1,r,ql,qr,c);
	st[1][o]=(st[1][o<<1]+st[1][o<<1|1])%mod;
	st[2][o]=(st[2][o<<1]+st[2][o<<1|1])%mod;
	st[3][o]=(st[3][o<<1]+st[3][o<<1|1])%mod;
}

void update2(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		add[o]=add[o]*c%mod;
		mul[o]=mul[o]*c%mod;
		st[3][o]=((st[3][o]*c%mod)*c%mod)*c%mod;
		st[2][o]=(st[2][o]*c%mod)*c%mod;
		st[1][o]=st[1][o]*c%mod;
		return;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m)update2(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update2(o<<1|1,m+1,r,ql,qr,c);
	st[1][o]=(st[1][o<<1]+st[1][o<<1|1])%mod;
	st[2][o]=(st[2][o<<1]+st[2][o<<1|1])%mod;
	st[3][o]=(st[3][o<<1]+st[3][o<<1|1])%mod;
}

int query(int o,int l,int r,int ql,int qr,int p){
	if(ql<=l&&qr>=r){
		return st[p][o];
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	int ans=0;
	if(ql<=m)ans=(ans+query(o<<1,l,m,ql,qr,p))%mod;
	if(qr>=m+1)ans=(ans+query(o<<1|1,m+1,r,ql,qr,p))%mod;
	return ans;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		build(1,1,n);
		for(int i=1;i<=m;++i){
			int t,l,r,p;
			scanf("%d%d%d%d",&t,&l,&r,&p);
			if(t==1)update1(1,1,n,l,r,p);
			else if(t==2)update2(1,1,n,l,r,p);
			else if(t==3)update3(1,1,n,l,r,p);
			else if(t==4)printf("%d\n",query(1,1,n,l,r,p));
		}
	}
	return 0;
}
