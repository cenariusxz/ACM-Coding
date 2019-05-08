#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

ll dp[2];

int main(){
	int n;
	scanf("%d",&n);
	dp[0]=1;
	dp[1]=0;
	for(int i=1;i<=n;++i){
		ll t=dp[1];
		dp[1]=(dp[1]*2%mod+dp[0]*3%mod)%mod;
		dp[0]=t;
	}
	printf("%I64d\n",dp[0]);
	return 0;
}
