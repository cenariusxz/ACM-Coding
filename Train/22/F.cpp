#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

inline int max(int a,int b){return a>b?a:b;}

const int maxn=256;
const int INF=0x3f3f3f3f;

char s[maxn];
char t[maxn];

int dp[maxn][maxn][3];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(s,0,sizeof(s));
		scanf("%s%s",s+1,t+1);
		int l1=strlen(s+1);
		int l2=strlen(t+1);
		for(int i=l1;i>=1;--i)s[i+l2]=s[i];
		for(int i=1;i<=l2;++i)s[i]='-';
		int ans=-4-3*l2;
		for(int k=1;k<=l1+l2;++k){
			for(int i=0;i<=l1+l2;++i){
				for(int j=0;j<=l2;++j){
					dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=-INF;
				}
			}
			if(s[k]=='-')dp[k][1][0]=-7;
			else if(s[k]==t[1])dp[k][1][0]=8;
			else dp[k][1][0]=-5;
			for(int i=k;i<=l1+l2;++i){
				for(int j=1;j<=l2;++j){
					if(i==k&&j==1)continue;
					if(s[i]=='-'){
						dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][0]-3);
						continue;
					}
					int add=s[i]==t[j]?8:-5;
					dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][0]+add);
					dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][1]+add);
					dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][2]+add);
					dp[i][j][1]=max(dp[i][j][1],dp[i][j-1][0]-7);
					dp[i][j][1]=max(dp[i][j][1],dp[i][j-1][1]-3);
					dp[i][j][1]=max(dp[i][j][1],dp[i][j-1][2]-7);
					dp[i][j][2]=max(dp[i][j][2],dp[i-1][j][0]-7);
					dp[i][j][2]=max(dp[i][j][2],dp[i-1][j][1]-7);
					dp[i][j][2]=max(dp[i][j][2],dp[i-1][j][2]-3);
				}
			}
			for(int i=k;i<=l1+l2;++i)ans=max(ans,dp[i][l2][0]);
			for(int j=1;j<=l2;++j){
				ans=max(ans,dp[l1+l2][j][0]-4-3*(l2-j));
				ans=max(ans,dp[l1+l2][j][1]-3*(l2-j));
				ans=max(ans,dp[l1+l2][j][2]-4-3*(l2-j));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
