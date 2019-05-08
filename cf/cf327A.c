#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
int dp[105],a[105],l[105];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=-1,s=0,i;
		memset(dp,0,sizeof(dp));
		memset(l,0,sizeof(l));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			s+=a[i];
			if(dp[i-1]>0){
				if(a[i]==1)dp[i]=dp[i-1]-1;
				else dp[i]=dp[i-1]+1;
				l[i]=l[i-1];
			}
			else {
				if(a[i]==1)dp[i]=-1;
				else dp[i]=1;
				l[i]=i;
			}
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans+s);
	}
	return 0;
}
