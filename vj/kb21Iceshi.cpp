#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double dp[5005][5005][2];
double C[5005][5005];

void init(){
	for(int i=0;i<=5000;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i&&j)?C[i-1][j]+C[i-1][j-1]:1;
		}
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n,s;
		scanf("%d%d",&n,&s);
		int Y=s-2*n;
		int N=n-Y;
		//		printf("%d %d\n",Y,N);
		dp[0][0][1]=1;
		dp[0][0][0]=0;
		double ans=0;
		for(int i=0;i<=Y;++i){
			for(int j=0;j<=N;++j){
				if(i==0&&j==0)continue;
				dp[i][j][0]=dp[i][j][1]=0;
			}
		}
		for(int i=0;i<=Y;++i){
			for(int j=0;j<=N;++j){
				if(i<Y){
					dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1];
					ans+=dp[i][j][0]*(C[n-i-j-1][N-j]);
				}
				if(j<N){
					dp[i][j+1][0]+=dp[i][j][0]+dp[i][j][1];
					ans+=dp[i][j][1]*(C[n-i-j-1][Y-i]);
				}
			}
		}
		//		for(int i=0;i<=Y;++i){
		//			for(int j=0;j<=N;++j){
		//				printf("dp[%d][%d][0]=%.2lf dp[%d][%d][1]=%.2lf\n",i,j,dp[i][j][0],i,j,dp[i][j][1]);
		//			}
		//		}
		double sum=dp[Y][N][0]+dp[Y][N][1];
		printf("%.10lf\n",sum);
		printf("Case %d: %.10lf\n",q,ans/sum);

	}
	return 0;
}
