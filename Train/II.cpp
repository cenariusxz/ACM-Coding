#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct seg{
	int x,y;
	bool operator < (const seg a)const{
		if(x==0)return 1;
		if(a.x==0)return 0;
		return y*a.x>x*a.y;
	}
}a[55];

int dp[55][2550];
int mi[55],ma[55];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n,K;
		scanf("%d%d",&n,&K);
		for(int i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
		sort(a+1,a+n+1);
		memset(dp,-1,sizeof(dp));
		memset(mi,0x3f,sizeof(mi));
		memset(ma,-1,sizeof(ma));
		mi[0]=ma[0]=dp[0][0]=0;
		mi[1]=ma[1]=dp[1][a[1].y]=a[1].x*a[1].y;
		for(int i=1;i<n;++i){
			int stx=max(0,K+i-n),lim=min(i,K-1);
			for(int j=lim;j>=stx;--j){
				for(int k=mi[j];k<=ma[j];++k){
					if(dp[j][k]==-1)continue;
					dp[j+1][k+a[i+1].y]=max(dp[j+1][k+a[i+1].y],dp[j][k]+k*a[i+1].x*2+a[i+1].x*a[i+1].y);
					if(k+a[i+1].y>ma[j+1])ma[j+1]=k+a[i+1].y;
					if(k+a[i+1].y<mi[j+1])mi[j+1]=k+a[i+1].y;
				}
			}
		}
		int ans=0;
		for(int i=mi[K];i<=ma[K];++i){
			ans=max(ans,dp[K][i]);
		}
		printf("Case %d: %d\n",q,ans);
	}
	return 0;
}

