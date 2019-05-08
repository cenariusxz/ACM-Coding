#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=3e5+5;
const int INF=0x3f3f3f3f;
const int maxl=20;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int a[maxn];
int n;
int maxx=0;
int que[maxn],cnt=0;
int tmp;
int G[maxn][maxl],prelog[maxn];

void initRMQ(int n){
	for(int i=2;i<=n;++i){
		prelog[i]=prelog[i-1];
		if((i&(-i))==i)prelog[i]++;
	}
	for(int i=1;i<=n;i++)G[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			G[i][j]=gcd(G[i][j-1],G[i+(1<<(j-1))][j-1]);
		}
	}
}

int askRMQ(int l,int r){
	if(l>r)swap(l,r);
	int k=prelog[r-l+1];
	return gcd(G[l][k],G[r-(1<<k)+1][k]);
}

void solve(){
	initRMQ(n);
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		int ans1=INF,ans2=-INF;
		while(l<=r){
			int m=l+((r-l)>>1);
			if(askRMQ(m,i)==a[i]){
				ans1=min(ans1,m);
				r=m-1;
			}
			else l=m+1;
		}
		l=i,r=n;
		while(l<=r){
			int m=l+((r-l)>>1);
			if(askRMQ(i,m)==a[i]){
				ans2=max(ans2,m);
				l=m+1;
			}
			else r=m-1;
		}
//		if(i==4)printf("%d %d\n",ans1,ans2);
		int ans=ans2-ans1;
		if(ans>maxx){
			maxx=ans;
			cnt=0;
			que[++cnt]=ans1;
		}
		else if(ans==maxx){
			que[++cnt]=ans1;
		}
	}
	int ans=1;
	for(int i=2;i<=cnt;++i){
		if(que[i]!=que[i-1])que[++ans]=que[i];
	}
	printf("%d %d\n",ans,maxx);
	for(int i=1;i<=ans;++i){
		printf("%d ",que[i]);
	}
	printf("\n");
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	solve();
	return 0;
}
