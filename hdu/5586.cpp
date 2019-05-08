#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
const int mod=1e4+7;

int a[maxn];
int dp[maxn];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int sum=0;
		for(int i=1;i<=n;++i){
			int num;
			scanf("%d",&num);
			a[i]=(num*1890+143)%mod-num;
			sum+=num;
		}
		dp[1]=a[1];
		int ans=a[1];
		for(int i=2;i<=n;++i){
			dp[i]=dp[i-1]>=0?dp[i-1]+a[i]:a[i];
			if(dp[i]>ans)ans=dp[i];
		}
		printf("%d\n",ans>0?sum+ans:sum);
	}
	return 0;
}
