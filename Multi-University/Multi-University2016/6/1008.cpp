#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e3+5;

ll dp[2][maxn][maxn];
int a[maxn];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,s;
		scanf("%d%d",&n,&s);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		int mink=0,maxk=0;
		for(int i=1;i<=n;++i){
			memset(dp[1],0,sizeof(dp[1]));
			for(int j=0;j<i;++j){
				for(int k=mink;k<=min(maxk,s-a[i]);++k){
					if(dp[0][j][k]){
						dp[1][j+1][k+a[i]]+=dp[0][j][k];
						if(dp[1][j+1][k+a[i]]>=mod)dp[1][j+1][k+a[i]]-=mod;
					}
				}
			}
			for(int j=0;j<i;++j){
				for(int k=mink;k<=min(maxk,s-a[i]);++k){
					dp[0][j+1][k+a[i]]+=dp[1][j+1][k+a[i]];
					if(dp[0][j+1][k+a[i]]>=mod)dp[0][j+1][k+a[i]]-=mod;
				}
			}
			maxk=min(s,maxk+a[i]);
		}
		ll ans=0;
		for(int i=2;i<=n-2;++i){
			ll sum=0;
			for(int j=0;j<=s;++j){
				sum+=dp[0][i][j];
				if(sum>=mod)sum-=mod;
			}
			ans=ans+sum*i%mod*(i-1)%mod*(n-i)%mod*(n-i-1)%mod;
			if(ans>=mod)ans-=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
