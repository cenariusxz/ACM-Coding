#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=105;
const int INF=0x3f3f3f3f;

char s[maxn][maxn];
int dp[maxn][maxn][2];		// 0->right 1->down
int n,m;

void init(){
	memset(dp,0x3f,sizeof(dp));
	if(s[1][1]=='.')dp[1][1][0]=0;
	else dp[1][1][0]=1;
}

void solve(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==1&&j==1)continue;
			if(j-1>=1){
				dp[i][j][0]=min(dp[i][j][0],dp[i][j-1][0]);
				if(i==n||s[i+1][j-1]=='b')dp[i][j][0]=min(dp[i][j][0],dp[i][j-1][1]);
				else dp[i][j][0]=min(dp[i][j][0],dp[i][j-1][1]+1);
			}
			if(i-1>=1){
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
				if(j==m||s[i-1][j+1]=='b')dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]);
				else dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+1);
			}
			if(s[i][j]=='b'){
				dp[i][j][0]++;
				dp[i][j][1]++;
			}
		}
	}
	printf("%d\n",min(dp[n][m][0],dp[n][m][1]));
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	init();
	solve();
	return 0;
}
