#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double dp[1001][1001];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		int n,m;
		scanf("%d%d",&n,&m);
		dp[1][0]=n*1.0/(n+m);
		for(int i=1;i<=n+m-1;++i){
			for(int j=(i+1)/2;j<=min(i,n);++j){
				int p=i-j;
				if(p>=j)continue;
				if(j<n)dp[j+1][p]+=dp[j][p]*(n-j)*1.0/(n+m-i);
				if(p<m&&p+1<j)dp[j][p+1]+=dp[j][p]*(m-p)*1.0/(n+m-i);
			}
		}
		printf("%.5lf\n",dp[n][m]);
	}
	return 0;
}
