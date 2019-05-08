#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=100007;

ll dp[1005][1005],dp2[1005][1005];
char a[1005];

ll dfs(int l,int r);
ll dfs2(int l,int r);

ll dfs(int l,int r){
	if(l>r)return 0;
	if(~dp[l][r])return dp[l][r];
	int i;
	if(a[l]==a[r]){
		dp[l][r]=(2*dfs(l+1,r-1)+1)%mod;
		for(i=1;i<=(r-l);i++){
			dp[l][r]=(dp[l][r]+(dfs2(l+i,r)+dfs2(l,r-i)))%mod;
		}
		return dp[l][r];
	}
	dp[l][r]=dfs(l+1,r-1);
	for(i=1;i<=(r-l);i++){
		dp[l][r]=(dp[l][r]+(dfs2(l+i,r)+dfs2(l,r-i)))%mod;
	}
	return dp[l][r];
}

ll dfs2(int l,int r){
	if(l>r)return 0;
	if(~dp2[l][r])return dp2[l][r];
	if(a[l]==a[r]){
		dp2[l][r]=(dfs(l+1,r-1)+1)%mod;
		return dp2[l][r];
	}
	dp2[l][r]=0;
	return dp2[l][r];
}

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			memset(dp,-1,sizeof(dp));
			memset(dp2,-1,sizeof(dp2));
			scanf("%s",a+1);
			int l=strlen(a+1),i;
			for(i=1;i<=l;i++)dp[i][i]=dp2[i][i]=1;
			ll ans=dfs(1,l)%mod;
			printf("Case #%d: %lld\n",q,ans);
		}
	}
	return 0;
}
