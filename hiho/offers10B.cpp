#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int mod=1e9+7;

char s[maxn];
ll dp[maxn][2][3];

int main(){
	int n;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<=n-1;++i){
		dp[i+1][0][0]=(dp[i][0][0]+dp[i][0][1]+dp[i][0][2])%mod;
		dp[i+1][0][1]=(dp[i][0][0]);
		dp[i+1][1][0]=(dp[i][0][0]+dp[i][0][1]+dp[i][0][2]+dp[i][1][0]+dp[i][1][1]+dp[i][1][2])%mod;
		dp[i+1][0][2]=(dp[i][0][1]);
		dp[i+1][1][1]=(dp[i][1][0]);
		dp[i+1][1][2]=(dp[i][1][1]);
	}
	ll sum=0;
	for(int i=0;i<=1;++i){
		for(int j=0;j<=2;++j){
			sum+=dp[n][i][j];
			sum%=mod;
		}
	}
	printf("%d\n",(int)sum);
	return 0;
}
