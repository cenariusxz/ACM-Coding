#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;

int a[maxn];
int dp[2][2][1005];
bool vis[2][2][1005];
int n,m;

int text1(){
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	dp[1][1][1]=a[1];
	vis[1][1][1]=1;
	dp[1][0][0]=0;
	vis[1][0][0]=1;
	for(int k=1;k<n;++k){
		int i=k&1;
		memset(vis[i^1],0,sizeof(vis[i^1]));
		for(int j=0;j<=m;++j){
			if(vis[i][0][j]){
				if(!vis[i^1][0][j]){
					vis[i^1][0][j]=1;
					dp[i^1][0][j]=dp[i][0][j];
				}
				else if(dp[i][0][j]>dp[i^1][0][j])dp[i^1][0][j]=dp[i][0][j];
				if(!vis[i^1][1][j+1]){
					vis[i^1][1][j+1]=1;
					dp[i^1][1][j+1]=dp[i][0][j]+a[k+1];
				}
				else if(dp[i][0][j]+a[k+1]>dp[i^1][1][j+1])dp[i^1][1][j+1]=dp[i][0][j]+a[k+1];
			}
			if(vis[i][1][j]){
				if(!vis[i^1][0][j]){
					vis[i^1][0][j]=1;
					dp[i^1][0][j]=dp[i][1][j];
				}
				else if(dp[i][1][j]>dp[i^1][0][j])dp[i^1][0][j]=dp[i][1][j];
				if(!vis[i^1][1][j]){
					vis[i^1][1][j]=1;
					dp[i^1][1][j]=dp[i][1][j]+a[k+1];
				}
				else if(dp[i][1][j]+a[k+1]>dp[i^1][1][j])dp[i^1][1][j]=dp[i][1][j]+a[k+1];
				if(!vis[i^1][1][j+1]){
					vis[i^1][1][j+1]=1;
					dp[i^1][1][j+1]=dp[i][1][j]+a[k+1];
				}
				else if(vis[i^1][1][j+1]&&dp[i][1][j]+a[k+1]>dp[i^1][1][j+1])dp[i^1][1][j+1]=dp[i][1][j]+a[k+1];
			}
		}
	}
	int ans=-0x3f3f3f3f;
	if(vis[n&1][1][m])ans=max(ans,dp[n&1][1][m]);
	if(vis[n&1][0][m])ans=max(ans,dp[n&1][0][m]);
	return ans;
}

#define MAXN 1000000
#define INF 0x7fffffff
int dp1[MAXN+10];
int mmax[MAXN+10];
int text2(){
	int i,j,mmmax;
	for(i=1;i<=n;i++){
		mmax[i]=0;
		dp1[i]=0;
	}
	dp1[0]=0;
	mmax[0]=0;    
	for(i=1;i<=m;i++){
		mmmax=-INF;
		for(j=i;j<=n;j++){
			dp1[j]=max(dp1[j-1]+a[j],mmax[j-1]+a[j]);
			mmax[j-1]=mmmax;
			mmmax=max(mmmax,dp1[j]);
		}    
	}  
	return mmmax;
}

int main(){
	srand(time(NULL));
	for(int i=1;i<=10;++i){
		n=rand()%1000+1;
		m=rand()%n+1;
		for(int i=1;i<=n;++i)a[i]=rand()%6000-3000;
		int a1=text1(),a2=text2();
		if(a1==a2)printf("AC\n");
		else{
			printf("WA\n");
			printf("%d %d ",m,n);
			for(int i=1;i<=n;++i)printf("%d ",a[i]);
			printf("\ni:%d k:%d\n",a1,a2);
		}
	}
}
