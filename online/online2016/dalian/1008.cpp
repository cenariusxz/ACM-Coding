#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
const int maxn=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int l,r,id;
	bool operator <(const node a)const{
		if(l==a.l)return r<a.r;
		return l<a.l;
	}
}q[maxn];

int ans[maxn];
int a[maxn];
int st[maxn][32];
int prelog[maxn];
int n,m;

void initST(int n){
	prelog[1]=0;
	for(int i=2;i<=n;++i){
		prelog[i]=prelog[i-1];
		if((1<<prelog[i]+1)==i)++prelog[i];
	}
	for(int i=n-1;i>=0;--i){
		st[i][0]=i;
		for(int j=1;i+(1<<j)-1<n;++j){
			st[i][j]=a[st[i][j-1]]<=a[st[i+(1<<j-1)][j-1]]?st[i][j-1]:st[i+(1<<j-1)][j-1];
		}
	}
}

int queryST(int l,int r){
	if(l==r)return r;
	int k=prelog[r-l+1];
	return a[st[l][k]]<=a[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}

void solve(){
	initST(n);
	
	q[0].l=-1;
	int l,r,now;
	for(int i=1;i<=m;++i){
		if(q[i].l!=q[i-1].l){
			l=q[i].l;
			r=l;
			now=a[l];
		}
		if(now==0)r=q[i].r;
		while(r<q[i].r){
			if(a[queryST(r+1,q[i].r)]>now){
				r=q[i].r;
			}
			else{
				int ql=r+1,qr=q[i].r;
				int pos=INF;
				while(ql<=qr){
					int mid=(ql+qr)>>1;
					
					if(a[queryST(r+1,mid)]<=now){
						pos=min(pos,mid);
						qr=mid-1;
					}
					else ql=mid+1;
				}
				r=pos;
				now%=a[pos];
			}
		}
		ans[q[i].id]=now;
	}
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<=n-1;++i)scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;++i){
			scanf("%d%d",&q[i].l,&q[i].r);
			q[i].l--;
			q[i].r--;
			q[i].id=i;
		}
		sort(q+1,q+m+1);
		solve();
	}
	return 0;
}
