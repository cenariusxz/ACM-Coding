#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=1e9+7;

ll dp[2005][2005];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	memset(dp,0,sizeof(dp));
	int i,j;
	if(k==1){printf("%d\n",n);return 0;}
	for(i=1;i<=n;i++){
		dp[1][i]=1;
	}
	ll ans=0;
	int p;
	for(i=1;i<k;i++){
		for(j=1;j<=n;j++){
			for(p=j;p<=n;p+=j){
				dp[i+1][p]=(dp[i+1][p]+dp[i][j])%mod;
			}
		}
	}
	for(i=1;i<=n;i++)ans=(ans+dp[k][i])%mod;
	printf("%lld\n",ans);
	return 0;
}
