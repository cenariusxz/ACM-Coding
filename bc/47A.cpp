#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[1005];
ll dp[1005];

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		int n,p;
		for(int q=1;q<=T;q++){
		scanf("%d%d",&n,&p);
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		int j;
		ll ans=a[1];
		for(i=1;i<=n;i++){
			if(i==1)dp[1]=p;
			else dp[1]=a[1];
			ll temp=dp[1];
			for(j=2;j<=n;j++){
				if(j==i){
					if(dp[j-1]>=0){
						dp[j]=dp[j-1]+p;
					}
					else dp[j]=p;
				}
				else{
					if(dp[j-1]>=0){
						dp[j]=dp[j-1]+a[j];
					}
					else dp[j]=a[j];
				}
				if(dp[j]>temp)temp=dp[j];
			}
			if(temp>ans)ans=temp;
		}
		printf("%lld\n",ans);
		}
	}
	return 0;
}
