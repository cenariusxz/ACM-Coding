#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;

int a[maxn];
int dp[maxn];

int main(){
	int n;
	while(~scanf("%d",&n)){
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	a[0]=-0x3f3f3f3f;
	a[n+1]=0x3f3f3f3f;
	memset(dp,0,sizeof(dp));
	int ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]>a[i-1])dp[i]=dp[i-1]+1;
		else dp[i]=1;
		if(dp[i]>ans)ans=dp[i];
	}
	bool f=0;
	int pre=dp[n];
	for(int i=n;i>=1;--i){
		if(f){
			if(dp[i]!=1){
				pre=dp[i];
				f=0;
			}
		}
		else{
			if(dp[i]==1){
				dp[i]=pre;
				f=1;
			}
			else{
				dp[i]=pre;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i-1]<a[i]&&a[i]<a[i+1])continue;
		else if(a[i]>a[i-1]){
			if(a[i-1]+1<a[i+1]){
				ans=max(ans,dp[i]+dp[i+1]);
			}
			else ans=max(ans,dp[i+1]+1);
		}
		else if(a[i]<a[i+1]){
			if(a[i-1]+1<a[i+1]){
				ans=max(ans,dp[i-1]+dp[i]);
			}
			else ans=max(ans,dp[i-1]+1);
		}
		else if(a[i-1]+1<a[i+1]){
			ans=max(ans,dp[i-1]+dp[i+1]);
		}
		else ans=max(ans,max(dp[i-1]+1,dp[i+1]+1));
	}
	printf("%d\n",ans);
	}
	return 0;
}
