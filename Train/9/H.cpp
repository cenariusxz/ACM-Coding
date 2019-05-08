#include<bits/stdc++.h>
using namespace std;
int n,a[5][1010];
int b[]={0,0,6,3,7,7,4,2,1,6,5,3,7};
int ok[10][15]={
	{0,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,0,1,1,0,1,0,0,0},
	{0,1,1,1,1,1,1,0,1,0,1,0,0},
	{0,1,1,1,1,0,1,0,0,0,0,0,0},
	{0,1,1,1,0,1,0,1,1,0,0,1,0},
	{0,1,1,1,0,0,0,1,0,0,0,0,0},
	{0,1,1,1,0,1,0,0,1,0,0,0,0},
	{0,1,1,1,0,0,0,0,0,0,0,0,0}
};
long long dp[1010][10];

void fuck()
{
	int i,j,mask;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=3;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++){
		for(mask=0;mask<8;mask++){
			for(j=1;j<=12;j++){
				if(ok[mask][j]==0) continue;
				int v=0;
				if(j==2||j==5) v+=a[1][i]*a[2][i];
				if(j==3||j==4) v+=a[2][i]*a[3][i];
				if(j==4||j==6||j==9||j==10||j==12) v+=a[1][i-1]*a[1][i];
				if(j==7||j==9||j==11||j==12) v+=a[2][i-1]*a[2][i];
				if(j==5||j==8||j==10||j==11||j==12) v+=a[3][i-1]*a[3][i];
				dp[b[j]][i]=max(dp[b[j]][i],dp[mask][i-1]+v);
			}
		}
	}
	long long ans=0;
	for(i=0;i<8;i++) ans=max(ans,dp[i][n]);
	cout<<ans<<endl;
}

int main()
{
	int t=0;
	while(~scanf("%d",&n)&&n){
		printf("Case %d: ",++t);
		fuck();
	}
 return 0;
}
