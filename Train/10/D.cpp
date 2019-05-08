#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int mod=1e9+7;
int n,m;
int dp[13][5][5];
char s[13][13][10];

void fuck()
{
	int i,j,k,m1,m2,m3;
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%s",s[i][j]);
			s[i][j][4]=s[i][j][0];
			s[i][j][5]=s[i][j][1];
			s[i][j][6]=s[i][j][2];
		}
	for(i=1;i<=m;i++)
		for(m1=0;m1<4;m1++)
			for(m2=0;m2<4;m2++)
				dp[i][m1][m2]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			int dp0[13][5][5]={0};
			for(m1=0;m1<4;m1++)
				for(m2=0;m2<4;m2++)
					for(m3=0;m3<4;m3++){
						if(i>1&&s[i-1][j][2+m3]!=s[i][j][m1]) continue;
						if(j>1&&s[i][j-1][1+m2]!=s[i][j][3+m1]) continue;
						dp0[j][m2][m1]+=dp[j][m2][m3];
						dp0[j][m2][m1]%=mod;
					}
			for(k=j-2;k>=1;k--)
				for(m1=0;m1<4;m1++)
					for(m2=0;m2<4;m2++)
						for(m3=0;m3<4;m3++){
							dp0[k][m1][m2]+=dp0[k+1][m2][m3];
							dp0[k][m1][m2]%=mod;
						}
			for(m1=0;m1<4;m1++)
				for(m2=0;m2<4;m2++)
					for(m3=0;m3<4;m3++){
						if(i>1&&s[i-1][j][2+m3]!=s[i][j][m1]) continue;
						if(i>1&&j<m&&s[i-1][j+1][3+m2]!=s[i-1][j][1+m1]) continue;
						dp0[j+1][m1][m2]+=dp[j+1][m3][m2];
						dp0[j+1][m1][m2]%=mod;
					}
			for(k=j+1;k<m;k++)
				for(m1=0;m1<4;m1++)
					for(m2=0;m2<4;m2++)
						for(m3=0;m3<4;m3++){
							dp0[k][m1][m2]+=dp0[k-1][m3][m1];
							dp0[k][m1][m2]%=mod;
						}
			memcpy(dp,dp0,sizeof(dp));
			for(k=1;k<=m;k++)
				for(m1=0;m1<4;m1++)
					for(m2=0;m2<4;m2++)
						printf("dp[%d][%d][%d]=%d\n",k,m1,m2,dp[k][m1][m2]);
			printf("\n");
		}
	}
	int ans=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			ans=(ans+dp[1][i][j])%mod;
	printf("%d\n",ans);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case %d: \n",i);
		fuck();
	}
 return 0;
}
