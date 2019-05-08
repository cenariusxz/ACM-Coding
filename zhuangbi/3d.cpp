#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double dp[2550][51][51];

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof(dp));
		dp[1][1][1]=1;
		for(int i=1;i<n*m;++i){
			for(int j=1;j<=min(n,i);++j){
				for(int k=1;k<=min(m,i);++k){
					if(j==n&&k==m)continue;
					if(j<n&&k<m)dp[i+1][j+1][k+1]+=dp[i][j][k]*(n-j)*(m-k)/(n*m-i);
					if(j<n)dp[i+1][j+1][k]+=dp[i][j][k]*k*(n-j)/(n*m-i);
					if(k<m)dp[i+1][j][k+1]+=dp[i][j][k]*j*(m-k)/(n*m-i);
					if(i<j*k)dp[i+1][j][k]+=dp[i][j][k]*(j*k-i)/(n*m-i);
				}
			}
		}
		double ans=0;
		for(int i=1;i<=n*m;++i){
			ans+=i*dp[i][n][m];
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}
