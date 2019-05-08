#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int a[MAXN],b[MAXN];
int dp[MAXN][3]={0};

int main()
{
	freopen("vacations.in","r",stdin);
	freopen("vacations.out","w",stdout);
	int n,i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=(x&1);
		b[i]=(x&2);
	}
	for(i=1;i<=n;i++){
		if(a[i]) dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		else dp[i][1]=n;
		if(b[i]) dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		else dp[i][2]=n;
		dp[i][0]=min(dp[i-1][1]+1,dp[i-1][0]+1);
		dp[i][0]=min(dp[i][0],dp[i-1][2]+1);
	}
	printf("%d\n",min(min(dp[n][0],dp[n][1]),dp[n][2]));
 return 0;
}
