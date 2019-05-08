#include<stdio.h>
#include<string.h>

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

const int maxn=205;
const int INF=0x7fffffff;

int dp[maxn][maxn];
int a[maxn];

int main(){
	int T,c=0;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;++i){
			int num;
			scanf("%d",&num);
			sum+=num;
		}
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j+i-1<=n;++j){
				dp[j][j+i-1]=INF;
				for(int k=j;k<=j+i-1;++k){
					dp[j][j+i-1]=min(dp[j][j+i-1],dp[j][k-1]+dp[k+1][j+i-1]+a[j-1]+a[j+i]);
				}
			}
		}
		printf("Case #%d: %d\n",++c,sum+dp[1][n]);
	}
	return 0;
}
