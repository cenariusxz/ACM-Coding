#include<stdio.h>
#include<string.h>
using namespace std;
const int maxm=100005;

char s[maxm],tmp[maxm];
int st[26][(maxm<<2)+5],change[26][(maxm<<2)+5];

void build(int c,int o,int l,int r){
	if(l==r)st[c][o]=((int)(s[l]-'a')==c)?1:0;
	else{
		int m=l+((r-l)>>1);
		build(c,o<<1,l,m);
		build(c,o<<1|1,m+1,r);
		st[c][o]=st[c][o<<1]+st[c][o<<1|1];
	}
}

void pushup(int c,int o){
	st[c][o]=st[c][o<<1]+st[c][o<<1|1];
}

void pushdown(int c,int o,int l,int r){
	if(change[c][o]!=-1){
		change[c][o<<1]=change[c][o];
		change[c][o<<1|1]=change[c][o];
		int m=l+((r-l)>>1);
		st[c][o<<1]=(m-l+1)*change[c][o];
		st[c][o<<1|1]=(r-m)*change[c][o];
		change[c][o]=-1;
	}
}

void update(int c,int o,int l,int r,int ql,int qr,int x){
	if(ql<=l&&qr>=r){
		change[c][o]=x;
		st[c][o]=(r-l+1)*x;
		return;
	}
	pushdown(c,o,l,r);
	int m=l+((r-l)>>1);
	if(ql<=m)update(c,o<<1,l,m,ql,qr,x);
	if(qr>=m+1)update(c,o<<1|1,m+1,r,ql,qr,x);
	pushup(c,o);
}

int query(int c,int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return st[c][o];
	pushdown(c,o,l,r);
	int m=l+((r-l)>>1);
	int ans=0;
	if(ql<=m)ans+=query(c,o<<1,l,m,ql,qr);
	if(qr>=m+1)ans+=query(c,o<<1|1,m+1,r,ql,qr);
	return ans;
}

void solve(int c,int o,int l,int r){
	if(st[c][o]==r-l+1){
		for(int i=l;i<=r;i++){
			tmp[i]=c+'a';
		}
		return;
	}
	if(st[c][o]==0)return;
	pushdown(c,o,l,r);
	int m=l+((r-l)>>1);
	solve(c,o<<1,l,m);
	solve(c,o<<1|1,m+1,r);
}

int num[26];

int main(){
	int n,q,i,j;
	scanf("%d%d%s",&n,&q,s+1);
	memset(change,-1,sizeof(change));
	for(i=0;i<=25;i++)build(i,1,1,n);
	for(i=1;i<=q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		for(j=0;j<=25;j++){
			num[j]=query(j,1,1,n,l,r);
			if(num[j]){
				update(j,1,1,n,l,r,0);
			}
		}
		int pos=l;
		if(k){
			for(j=0;j<=25;j++){
				if(num[j]){
					update(j,1,1,n,pos,pos+num[j]-1,1);
					pos+=num[j];
				}
			}
		}
		else{
			for(j=25;j>=0;j--){
				if(num[j]){
					update(j,1,1,n,pos,pos+num[j]-1,1);
					pos+=num[j];
				}
			}
		}
	}
	for(i=0;i<=25;i++){
		solve(i,1,1,n);
	}
	for(i=1;i<=n;i++)printf("%c",tmp[i]);
	printf("\n");
	return 0;
}
