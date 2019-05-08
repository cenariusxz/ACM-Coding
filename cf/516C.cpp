#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
const int maxn=1e5+5;

ll h[maxn<<1],d[maxn<<1];
ll sum[maxn<<1];
ll a[maxn<<1][3];
int st[maxn<<3][3];
int n,m;

void build(int o,int l,int r){
	if(l==r){
		st[o][0]=st[o][1]=st[o][2]=l;
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o][0]=a[st[o<<1][0]][0]>=a[st[o<<1|1][0]][0]?st[o<<1][0]:st[o<<1|1][0];
	st[o][1]=a[st[o<<1][1]][1]>=a[st[o<<1|1][1]][1]?st[o<<1][1]:st[o<<1|1][1];
	st[o][2]=a[st[o<<1][2]][2]>=a[st[o<<1|1][2]][2]?st[o<<1][2]:st[o<<1|1][2];
}

int query(int o,int l,int r,int ql,int qr,int x){
	if(ql>qr)return 0;
	if(ql<=l&&qr>=r)return st[o][x];
	int m=l+((r-l)>>1);
	int ans=0;
	if(ql<=m){
		int tmp=query(o<<1,l,m,ql,qr,x);
		if(a[tmp][x]>a[ans][x])ans=tmp;
	}
	if(qr>=m+1){
		int tmp=query(o<<1|1,m+1,r,ql,qr,x);
		if(a[tmp][x]>a[ans][x])ans=tmp;
	}
	return ans;
}

ll get(int r,int l){
	int tmp1=query(1,1,n,r+1,l-1,0);
	int tmp2=query(1,1,n,r+1,l-1,1);
	if(tmp1==tmp2){
		int t21=query(1,1,n,r+1,tmp2-1,1);
		int t22=query(1,1,n,tmp2+1,l-1,1);
		int t2=a[t21][1]>=a[t22][1]?t21:t22;
		int t11=query(1,1,n,r+1,tmp1-1,0);
		int t12=query(1,1,n,tmp1+1,l-1,0);
		int t1=a[t11][0]>=a[t12][0]?t11:t12;
		return max(a[tmp1][0]+a[t2][1],a[t1][0]+a[tmp2][1]);
	}
	else return a[tmp1][0]+a[tmp2][1];
}

int main(){
	scanf("%d%d",&n,&m);
	sum[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%I64d",&d[i]);
		d[n+i]=d[i];
	}
	for(int i=1;i<=n;++i){
		scanf("%I64d",&h[i]);
		h[n+i]=h[i];
	}
	ll sum=0;
	for(int i=1;i<=n;++i){
		a[i][0]=sum+2*h[i];
		a[i][1]=-sum+2*h[i];
		sum+=d[i];
	}
	a[0][0]=a[0][1]=a[0][2]=-INF;
	a[n+1][0]=a[n+1][1]=a[n+2][2]=-INF;
	sum=0;
	for(int i=n;i>=1;--i){
		sum+=d[i];
		a[i][2]=2*h[i]+sum;
	}
	build(1,1,n);
	for(int i=1;i<=m;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l>r)printf("%I64d\n",get(r,l));
		else{
			ll ans=0;
			ans=max(ans,get(0,l));
			ans=max(ans,get(r,n+1));
			int tmp1=query(1,1,n,1,l-1,0);
			int tmp2=query(1,1,n,r+1,n,2);
			ans=max(ans,a[tmp1][0]+a[tmp2][2]);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
