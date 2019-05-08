#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e3+5;
const int mod=1e9+7;

int a[maxn],dp[maxn];
ll C[maxn][maxn];

void init(){
	for(int i=0;i<=1000;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i==0||j==0)?1:((C[i-1][j]+C[i-1][j-1])%mod);
		}
	}
}

int main(){
	int T;
	init();
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n,k;
		scanf("%d%d",&n,&k);
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		dp[1]=1;
		for(int i=2;i<=n;++i){
			dp[i]=1;
			for(int j=i-1;j>=1;--j){
				if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ll res=0;
		for(int i=1;i<=n;++i){
			if(dp[i]-1>=k-1){
				res=(res+C[dp[i]-1][k-1])%mod;
			}
		}
		printf("Case #%d: %lld\n",q,res);
	}
	return 0;

}
