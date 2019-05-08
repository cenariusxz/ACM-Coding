#include<stdio.h>
#include<string.h>
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;

int st[2][maxn];
char s[maxn];

int min(int a,int b){return a<b?a:b;}

void build(int o,int l,int r){
	if(l==r){
		if(s[l]=='L'){
			st[0][o]=l;
			st[1][o]=INF;
		}
		else{
			st[1][o]=l;
			st[0][o]=INF;
		}
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[0][o]=min(st[0][o<<1],st[0][o<<1|1]);
	st[1][o]=min(st[1][o<<1],st[1][o<<1|1]);
}

int query(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		return st[c][o];
	}
	int m=l+((r-l)>>1);
	int ans=INF;
	if(ql<=m)ans=min(ans,query(o<<1,l,m,ql,qr,c));
	if(qr>=m+1)ans=min(ans,query(o<<1|1,m+1,r,ql,qr,c));
	return ans;
}

void update(int o,int l,int r,int ind,int c){
	if(l==r){
		st[c][o]=INF;
		return;
	}
	int m=l+((r-l)>>1);
	if(ind<=m)update(o<<1,l,m,ind,c);
	else update(o<<1|1,m+1,r,ind,c);
	st[c][o]=min(st[c][o<<1],st[c][o<<1|1]);
}

int ans[maxn],cnt;

int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	build(1,1,n);
	int nl=0,nr=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='L')nl++;
		else nr++;
	}
	int x=0;
	cnt=0;
	if(nl>nr)x=0;
	else if(nl<nr)x=1;
	else if(s[1]=='L')x=0;
	else if(s[1]=='R')x=1;
	int pre=0;
	int num=0;
	for(int i=1;i<=n;++i){
		if(pre==n){
			num++;
			pre=0;
		}
		int tmp=query(1,1,n,pre+1,n,x);
		if(tmp==INF){
			num++;
			tmp=query(1,1,n,1,n,x);
		}
		ans[++cnt]=tmp;
		update(1,1,n,tmp,x);
		x^=1;
		pre=tmp;
	}
	printf("%d\n",num);
	for(int i=1;i<=cnt;++i){
		printf("%d",ans[i]);
		if(i==cnt)printf("\n");
		else printf(" ");
	}
}
