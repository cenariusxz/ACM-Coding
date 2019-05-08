#include<stdio.h>
#include<string.h>

int dp[100005],a[100005];
bool f[100005];

int main(){
	int n,m,i,j;
	memset(dp,0,sizeof(dp));
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=n;i>=1;i--){
		if(f[a[i]]){
			dp[i]=dp[i+1];
		}
		else{
			dp[i]=dp[i+1]+1;
			f[a[i]]=1;
		}
	}
	for(i=1;i<=m;i++){
		int t;
		scanf("%d",&t);
		printf("%d\n",dp[t]);
	}
	return 0;
}
