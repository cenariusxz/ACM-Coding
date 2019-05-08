#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;

int dp[2][maxn],a[maxn],b[maxn],st[maxn<<2];

void update(int o,int l,int r,int ind,int num){
	if(l==r){
		if(st[o]<num)st[o]=num;
		return;
	}
	int m=l+((r-l)>>1);
	if(ind<=m)update(o<<1,l,m,ind,num);
	else update(o<<1|1,m+1,r,ind,num);
	st[o]=max(st[o<<1],st[o<<1|1]);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		return st[o];
	}
	int m=l+((r-l)>>1);
	int ans=0;
	if(ql<=m)ans=max(ans,query(o<<1,l,m,ql,qr));
	if(qr>=m+1)ans=max(ans,query(o<<1|1,m+1,r,ql,qr));
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n,L;
		memset(st,0,sizeof(st));
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&L);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		int cnt=1;
		for(int i=2;i<=n;++i){
			if(b[i]!=b[i-1])b[++cnt]=b[i];
		}
		for(int i=1;i<=n;++i){
			int l=1,r=cnt;
			while(l<=r){
				int m=l+((r-l)>>1);
				if(b[m]<a[i])l=m+1;
				else if(b[m]>a[i])r=m-1;
				else{a[i]=m;break;}
			}
		}
		for(int i=1;i<=n;++i){
			dp[0][i]=query(1,0,cnt,0,a[i]-1)+1;
			update(1,0,cnt,a[i],dp[0][i]);
		}
		int res=0;
		for(int i=1;i+L<=n;++i)if(dp[0][i]>res)res=dp[0][i];
		memset(st,0,sizeof(st));
		for(int i=L+1;i<=n;++i){
			dp[1][i]=query(1,0,cnt,0,a[i]-1)+1;
			if(dp[1][i]>res)res=dp[1][i];
			update(1,0,cnt,a[i],dp[1][i]);
			update(1,0,cnt,a[i-L],dp[0][i-L]);
		}
		printf("Case #%d: ",q);
		printf("%d\n",res);
	}
	return 0;
}
