#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double dp[1005][1005];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int t,d;
		scanf("%d%d",&t,&d);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=t;++i){
			for(int j=0;j<=d;++j){
				if(i==0)dp[i][j]=1;
				else if(i%2)dp[i][j]=0;
				else{
					int num=i;
					if(i>=1&&j>=1)num+=i*j;
					if(i>=2)num+=i*(i-1)/2;
					if(i>=1&&j>=1)dp[i][j]+=dp[i][j-1]*i*j/num;
					if(i>=2)dp[i][j]+=dp[i-2][j]*i*(i-1)/2/num;
				}
			}
		}
		printf("Case %d: %.10lf\n",q,dp[t][d]);
	}
	return 0;
}
