#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

char s[4][105];
int dp[4][105];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&k);
		scanf("%s%s%s",s[1]+1,s[2]+1,s[3]+1);
		if(s[1][1]=='s')dp[1][1]=1;
		if(s[2][1]=='s')dp[2][1]=1;
		if(s[3][1]=='s')dp[3][1]=1;
		bool f=0;
		for(int i=1;i<n;){
			for(int j=1;j<=3;++j){
				if(dp[j][i]&&s[j][i+1]=='.'){
					i++;
					dp[j][i]=1;
					if(j-1>=1&&j-1<=3&&s[j-1][i]=='.')dp[j-1][i]=1;
					if(j+1>=1&&j+1<=3&&s[j+1][i]=='.')dp[j+1][i]=1;
					i--;
				}
			}
			i++;
			for(int j=1;j<=3;++j){
				if(dp[j][i]){
					if(i==n)f=1;
					else if(i==n-1&&dp[j][i+1]=='.')f=1;
					else if(s[j][i+1]=='.'&&s[j][i+2]=='.'){
						dp[j][i+2]=1;
					}
				}
			}
			i+=2;
		}
/*		for(int j=1;j<=3;++j){
			for(int i=1;i<=n;++i)printf("%d",dp[j][i]);
			printf("\n");
		}*/
		if(dp[1][n])f=1;
		if(dp[2][n])f=1;
		if(dp[3][n])f=1;
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
