#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

int C[5005][5005];
int A[5005];
int dp[5005][5005];

void init(){
	memset(C,0,sizeof(C));
	memset(dp,-1,sizeof(dp));
	A[0]=1;
	for(int i=1;i<=5000;++i)A[i]=A[i-1]*(ll)i%mod;
	for(int i=0;i<=5000;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i==0||j==0)?1:(C[i-1][j]+(ll)C[i-1][j-1])%mod;
		}
	}
}

int dfs(int i,int j){
	if(dp[i][j]!=-1)return dp[i][j];
	if(j>i)return 0;
	if(i==j)return dp[i][j]=1;
	if(j==0)return 0;
	int ans=0;
	for(int k=j;k<=i;++k){
		ans=(ans+dfs(k-1,j-1)*(ll)C[i-1][k-1]%mod*A[i-k]%mod)%mod;
	}
	return dp[i][j]=ans;
}

int main(){
	init();
	int n,l,r;
	while(scanf("%d%d%d",&n,&l,&r)!=EOF){
		if(n==0&&l==0&&r==0)break;
		int res=0;
		for(int m=l;m<=n-r+1;++m){
			int ans=C[n-1][m-1];
			ans=ans*(ll)dfs(m-1,l-1)%mod*(ll)dfs(n-m,r-1)%mod;
			res=(res+(ll)ans)%mod;
		}
		printf("%d\n",res);
	}
	return 0;
}
