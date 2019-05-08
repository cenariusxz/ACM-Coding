#include <bits/stdc++.h>
#define MAXN 505
using namespace std;
int n,s,w;
bool a[MAXN][MAXN],vis[105];
int c[MAXN],line[MAXN][MAXN],dp[MAXN];

void fuck()
{
	int i,j,k;
	int x;
	memset(a,0,sizeof(a));
	for(i=1;i<=w;i++){
		scanf("%d",&c[i]);
		for(j=1;j<=c[i];j++){
			scanf("%d",&x);
			a[x][i]=1;
		}
	}
	int cnt;
	memset(line,0x3f,sizeof(line));
	for(i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		cnt=0;
		for(j=i;j<=n&&j-i+1<=s;j++){
			for(k=1;k<=w;k++){
				if(!vis[k]&&a[j][k]){
					vis[k]=1;
					cnt++;
				}
			}
			if(j-i+1+cnt>s) break;
			line[i][j]=j-i+1+cnt;
			//printf(" line[%d][%d]=%d\n",i,j,line[i][j]);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(i=1;i<=n;i++){
		for(j=i;j>0&&line[j][i]<=s;j--){
			dp[i]=min(dp[i],dp[j-1]+line[j][i]);
		}
		//printf("dp[%d]=%d\n",i,dp[i]);
	}
	if(dp[n]>=0x3f3f3f) printf("-1\n");
	else printf("%d\n",dp[n]-n);
}

int main()
{
	int i,t=0;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d%d",&n,&s,&w);
		printf("Case %d: ",i);
		fuck();
	}
 return 0;
}
