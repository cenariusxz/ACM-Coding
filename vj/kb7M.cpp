#include<stdio.h>
#include<string.h>
const int maxm=100005;
const int INF=0x3f3f3f3f;

int st[2][maxm<<2],stl[2][maxm<<2],str[2][maxm<<2],stx[2][maxm<<2];
int la[2][maxm<<2];		//-1 beizhanyong 1 beiqingchu
int sta;
//nvshen 0 diaosi 1

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

void build(int o,int l,int r){
	st[0][o]=st[1][o]=stl[0][o]=stl[1][o]=str[0][o]=str[1][o]=r-l+1;
	stx[0][o]=stx[1][o]=l;
	la[0][o]=la[1][o]=1;
	if(l==r)return;
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
}

void pushup(int o,int l,int r,int t){
	int m=l+((r-l)>>1);
	if(stl[t][o<<1]==m-l+1)stl[t][o]=stl[t][o<<1]+stl[t][o<<1|1];
	else stl[t][o]=stl[t][o<<1];
	if(str[t][o<<1|1]==r-m)str[t][o]=str[t][o<<1]+str[t][o<<1|1];
	else str[t][o]=str[t][o<<1|1];
	if(st[t][o<<1]>st[t][o<<1|1]){
		st[t][o]=st[t][o<<1];
		stx[t][o]=stx[t][o<<1];
	}
	else{
		st[t][o]=st[t][o<<1|1];
		stx[t][o]=stx[t][o<<1|1];
	}
	if(str[t][o<<1]+stl[t][o<<1|1]>st[t][o]){
		st[t][o]=str[t][o<<1]+stl[t][o<<1|1];
		stx[t][o]=m-str[t][o<<1]+1;
	}
}

void pushdown(int o,int l,int r,int t){
	if(la[t][o]==-1){
		la[t][o<<1]=la[t][o<<1|1]=-1;
		stl[t][o<<1]=str[t][o<<1]=stl[t][o<<1|1]=str[t][o<<1|1]=st[t][o<<1]=st[t][o<<1|1]=0;
		stx[t][o<<1]=stx[t][o<<1|1]=INF;
		la[t][o]=0;
	}
	else if(la[t][o]==1){
		la[t][o<<1]=la[t][o<<1|1]=1;
		int m=l+((r-l)>>1);
		stl[t][o<<1]=str[t][o<<1]=st[t][o<<1]=m-l+1;
		stl[t][o<<1|1]=str[t][o<<1|1]=st[t][o<<1|1]=r-m;
		stx[t][o<<1]=l;
		stx[t][o<<1|1]=m+1;
		la[t][o]=0;
	}
}

void query(int o,int l,int r,int c,int t){
	if(st[t][o]>=c)sta=min(sta,stx[t][o]);
	else return;
	if(l==r)return;
	pushdown(o,l,r,t);
	int m=l+((r-l)>>1);
	if(str[t][o<<1]+stl[t][o<<1|1]>=c&&m-str[t][o<<1]+1<sta)sta=m-str[t][o<<1]+1;
	if(l<sta)query(o<<1,l,m,c,t);
	if(m+1<sta)query(o<<1|1,m+1,r,c,t);
}

void update(int o,int l,int r,int ql,int qr,int c,int t){
	if(ql<=l&&qr>=r){
		if(c==-1){
			la[t][o]=-1;
			stl[t][o]=str[t][o]=st[t][o]=0;
			stx[t][o]=INF;
		}
		else if(c==1){
			la[t][o]=1;
			stl[t][o]=str[t][o]=st[t][o]=r-l+1;
			stx[t][o]=l;
		}
		return;
	}
	pushdown(o,l,r,t);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c,t);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c,t);
	pushup(o,l,r,t);
}

char s[15];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("Case %d:\n",q);
		build(1,1,n);
		for(int i=1;i<=m;++i){
			scanf("%s",s);
			if(s[0]=='D'){
				int c;
				scanf("%d",&c);
				sta=INF;
				query(1,1,n,c,1);
				if(sta==INF)printf("fly with yourself\n");
				else{
					update(1,1,n,sta,sta+c-1,-1,1);
					printf("%d,let's fly\n",sta);
				}
			}
			else if(s[0]=='N'){
				int c;
				scanf("%d",&c);
				sta=INF;
				query(1,1,n,c,1);
				if(sta==INF){
					query(1,1,n,c,0);
					if(sta==INF)printf("wait for me\n");
					else{		
						update(1,1,n,sta,sta+c-1,-1,1);
						update(1,1,n,sta,sta+c-1,-1,0);
						printf("%d,don't put my gezi\n",sta);
					}
				}
				else{
					update(1,1,n,sta,sta+c-1,-1,1);
					update(1,1,n,sta,sta+c-1,-1,0);
					printf("%d,don't put my gezi\n",sta);
				}
			}
			else if(s[0]=='S'){
				int a,b;
				scanf("%d%d",&a,&b);
				update(1,1,n,a,b,1,1);
				update(1,1,n,a,b,1,0);
				printf("I am the hope of chinese chengxuyuan!!\n");
			}
		}
	}
}
