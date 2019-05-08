#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int n,K;
int ma[100005][20],mi[100005][20],c[25];
int a[100005];

inline int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void init(){
	memset(ma,0,sizeof(ma));
	memset(mi,0,sizeof(mi));
	for(int i=1;i<=n;i++)ma[i][0]=mi[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
		}
	}
}

int main(){
	c[0]=1;
	for(int i=1;i<=20;i++)c[i]=c[i-1]*2;
	int T;
	T=read();
	while(T--){
		n=read();
		K=read();
		int i,j;
		for(i=1;i<=n;i++)a[i]=read();
		init();
		ll ans=0;
		for(i=1;i<=n;i++){
			int l=i,r=n;
			while(l<=r){
				int mid=l+((r-l)>>1);
				int k=log(mid-i+1)*1.0/log(2);
				int Ma=max(ma[i][k],ma[mid-(1<<k)+1][k]);
				int Mi=min(mi[i][k],mi[mid-(1<<k)+1][k]);
				if(Ma-Mi>=K)r=mid-1;
				else l=mid+1;
			}
			ans=ans+r-i+1;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
