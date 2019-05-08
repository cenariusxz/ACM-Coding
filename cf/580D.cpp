#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=20;
const int INF=0x3f3f3f3f;
const int maxm=(1<<18)+10;

int ma[maxn][maxn];
ll dp[maxm][18];
int num[maxm];
int a[maxn];

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	memset(dp,-1,sizeof(dp));
	memset(ma,0,sizeof(ma));
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	while(k--){
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		ma[a][b]=v;
	}
	dp[0][0]=0;
	num[0]=0;
	ll ans=-1;
	for(int i=0;i<(1<<n);++i){
		if(num[i]>=m)continue;
		for(int j=1;j<=n;++j){
			if(!(i&(1<<(j-1)))){
				int tmp=i+(1<<(j-1));
				num[tmp]=num[i]+1;
				int minn;
				if(i==0)minn=0;
				else minn=1;
				for(int p=minn;p<=n;++p){
					if(~dp[i][p]){
						dp[tmp][j]=max(dp[tmp][j],dp[i][p]+a[j]+ma[p][j]);
						if(dp[tmp][j]>ans)ans=dp[tmp][j];
					}
				}
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
