#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
typedef long long ll;
const int INF=0x3f3f3f3f;

ll dp[2][maxn];

struct num{
	int a,b;
	bool operator < (const num x)const{
		if(a==x.a)return b>x.b;
		return a>x.a;
	}
}p[maxn];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		ll sum=0;
		for(int i=0;i<n;++i){
			scanf("%d",&p[i].a);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&p[i].b);
		}
		sort(p,p+n);
		for(int i=1;i<n;++i)sum+=p[i].b;
		memset(dp,0x3f,sizeof(dp));
		dp[1][0]=0;
		dp[1][1]=p[1].b;
		for(int i=2;i<n;++i){
			int now=i&1;
			int pre=!now;
			memset(dp[now],0x3f,sizeof(dp[now]));
			for(int j=i/2;j<=min(i,(n-1)/2);++j){
				dp[now][j]=min(dp[pre][j],dp[pre][j-1]+p[i].b);
			}
		}
		//	ll ans=(ll)1e16;
		//	for(int i=1;i<=n;++i){
		//		ans=min(ans,dp[i][(n-1)/2]);
		//	}
		printf("%lld\n",sum-dp[(n-1)&1][(n-1)/2]);
	}
	return 0;
}
