#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define max(a,b) a>b?a:b

int dp[105][105];
int a[105],b[105];

int main(){
	int n,m;
	int i,j,ans=0;
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i]-b[j]>=-1&&a[i]-b[j]<=1){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
