#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int p[30005];
int dp[30005][605][2];

int main(){
	int n,d,i;
	memset(p,0,sizeof(p));
	scanf("%d%d",&n,&d);
	int maxx=0;
	for(i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(a>maxx)maxx=a;
		p[a]++;
	}
	memset(dp,0,sizeof(dp));
	dp[d][d-d+250][1]=p[d];
	dp[d][d-d+250][0]=1;
	int ans=p[d];
	for(i=d;i<=maxx;i++){
		for(int j=max(d-250,1);j<=d+250;j++){
			if(dp[i][j-d+250][0]){
				if(i+j<=maxx){
					dp[i+j][j-d+250][0]=1;
					dp[i+j][j-d+250][1]=max(dp[i+j][j-d+250][1],dp[i][j-d+250][1]+p[i+j]);
					if(dp[i+j][j-d+250][1]>ans)ans=dp[i+j][j-d+250][1];
				}
				if(i+j+1<=maxx){
					dp[i+j+1][j+1-d+250][0]=1;
					dp[i+j+1][j+1-d+250][1]=max(dp[i+j+1][j+1-d+250][1],dp[i][j-d+250][1]+p[i+j+1]);
					if(dp[i+j+1][j+1-d+250][1]>ans)ans=dp[i+j+1][j+1-d+250][1];
				}
				if(i+j-1<=maxx&&j-1>0){
					dp[i+j-1][j-1-d+250][0]=1;
					dp[i+j-1][j-1-d+250][1]=max(dp[i+j-1][j-1-d+250][1],dp[i][j-d+250][1]+p[i+j-1]);
					if(dp[i+j-1][j-1-d+250][1]>ans)ans=dp[i+j-1][j-1-d+250][1];
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
