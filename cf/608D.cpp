#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

const int maxn=505;

int dp[maxn][maxn];
int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)dp[i][i]=1;
	for(int len=2;len<=n;++len){
		for(int i=1;i<=n-len+1;++i){
			int j=i+len-1;
			if(a[i]!=a[j]){
				if(len==2)dp[i][j]=2;
				else{
					int m=INF;
					for(int k=i+1;k<=j;++k){
						if(dp[i][k-1]+dp[k][j]<m)m=dp[i][k-1]+dp[k][j];
					}
					dp[i][j]=m;
				}
			}
			else{
				if(len==2)dp[i][j]=1;
				else{
					dp[i][j]=dp[i+1][j-1];
					int m=INF;
					for(int k=i+1;k<=j;++k){
						if(dp[i][k-1]+dp[k][j]<m)m=dp[i][k-1]+dp[k][j];
					}
					dp[i][j]=min(dp[i][j],m);
				}
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}
