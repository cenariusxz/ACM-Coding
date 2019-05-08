#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxnum=1e7+5;
const int maxn=1e5+5;

int st[maxn<<2],cha[maxn<<2];
int a[maxn];
int prime[664600];
bool vis[maxnum];

void init(){
	int n=1e7;
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=2;i<n;i++){
		if(!vis[i])prime[cnt++]=i;
		for(int j=0;j<cnt&&i*prime[j]<n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	vis[1]=1;
}

void build(int o,int l,int r){
	if(l==r){
		if(vis[a[l]])st[o]=0;
		else st[o]=1;
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o]=st[o<<1]+st[o<<1|1];
}

void change(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		cha[o]=c;
		if(vis[c])st[o]=0;
		else st[o]=r-l+1;
		return;
	}
	int m=l+((r-l)>>1);
	if(cha[o]){
		cha[o<<1]=cha[o];
		cha[o<<1|1]=cha[o];
		if(vis[cha[o]])st[o<<1]=st[o<<1|1]=0;
		else{
			st[o<<1]=m-l+1;
			st[o<<1|1]=r-m;
		}
		cha[o]=0;
	}
	if(ql<=m)change(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)change(o<<1|1,m+1,r,ql,qr,c);
	st[o]=st[o<<1]+st[o<<1|1];
}

int get(int o,int l,int r,int ind){
	if(l==r){
		if(cha[o])return cha[o];
		else return a[l];
	}
	int m=l+((r-l)>>1);
	if(cha[o]){
		cha[o<<1]=cha[o];
		cha[o<<1|1]=cha[o];
		if(vis[cha[o]])st[o<<1]=st[o<<1|1]=0;
		else{
			st[o<<1]=m-l+1;
			st[o<<1|1]=r-m;
		}
		cha[o]=0;
	}
	if(ind<=m)return get(o<<1,l,m,ind);
	else return get(o<<1|1,m+1,r,ind);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		return st[o];
	}
	int m=l+((r-l)>>1);
	if(cha[o]){
		cha[o<<1]=cha[o];
		cha[o<<1|1]=cha[o];
		if(vis[cha[o]])st[o<<1]=st[o<<1|1]=0;
		else{
			st[o<<1]=m-l+1;
			st[o<<1|1]=r-m;
		}
		cha[o]=0;
	}
	int ans=0;
	if(ql<=m)ans+=query(o<<1,l,m,ql,qr);
	if(qr>=m+1)ans+=query(o<<1|1,m+1,r,ql,qr);
	return ans;
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,q;
		scanf("%d%d",&n,&q);
		memset(cha,0,sizeof(cha));
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		build(1,1,n);
		int a,b,c;
		while(q--){
			char s[10];
			scanf("%s",s);
			if(s[0]=='Q'){
				scanf("%d%d",&a,&b);
				printf("%d\n",query(1,1,n,a,b));
			}
			else if(s[0]=='R'){
				scanf("%d%d%d",&c,&a,&b);
				change(1,1,n,a,b,c);
			}
			else if(s[0]=='A'){
				scanf("%d%d",&a,&b);
				a+=get(1,1,n,b);
				change(1,1,n,b,b,a);
			}
		}
	}
	return 0;
}
