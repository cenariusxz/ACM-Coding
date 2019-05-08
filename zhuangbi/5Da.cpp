#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=205;

inline ll max(ll a,ll b){return a>b?a:b;}

ll a[maxn],dp[maxn][maxn];

int main(){
	int T,cnt=0;
	scanf("%d",&T);
	while(T--){
		ll ans=0;
		int n;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;++i){
			int num;
			scanf("%d",&num);
			ans+=num;
		}
		for(int i=1;i<=n;++i){
			scanf("%I64d",&a[i]);
		}
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				for(int k=i;k<j;++k){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp)
				}
			}
		}
		printf("Case #%d: &I64d\n",++cnt,dfs(1,n,0,0));
	}
	return 0;
}
