#include<stdio.h>
#include<string.h>
const int INF=-0x3f3f3f3f;

int a[305][305],dp[305][305],fa[305][305][2];bool vi[305][305];

int mmax(int a,int b){
	return a>b;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}

		memset(dp,0,sizeof(dp));
		memset(vi,0,sizeof(vi));
		fa[1][1][0]=fa[1][1][1]=-1;
		dp[1][1]=a[1][1];
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i-1>=1){
					if(!vi[i][j]||dp[i-1][j]+a[i][j]>dp[i][j]){
						dp[i][j]=dp[i-1][j]+a[i][j];
						fa[i][j][0]=i-1;
						fa[i][j][1]=j;
						vi[i][j]=1;
					}
				}
				if(j-1>=1){
					if(!vi[i][j]||dp[i][j-1]+a[i][j]>dp[i][j]){
						dp[i][j]=dp[i][j-1]+a[i][j];
						fa[i][j][0]=i;
						fa[i][j][1]=j-1;
						vi[i][j]=1;
					}
				}
			}
		}
		int ans=dp[n][n];
		memset(dp,0,sizeof(dp));
		memset(vi,0,sizeof(vi));
		a[n][n]=0;
		i=fa[n][n][0];
		j=fa[n][n][1];
		while(i!=-1&&j!=-1){
			a[i][j]=0;
			int ii=fa[i][j][0];
			int jj=fa[i][j][1];
			i=ii;j=jj;
		}

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i-1>=1){
					if(!vi[i][j]||dp[i-1][j]+a[i][j]>dp[i][j]){
						dp[i][j]=dp[i-1][j]+a[i][j];
						vi[i][j]=1;
					}
				}
				if(j-1>=1){
					if(!vi[i][j]||dp[i][j-1]+a[i][j]>dp[i][j]){
						dp[i][j]=dp[i][j-1]+a[i][j];
						vi[i][j]=1;
					}
				}
			}
		}
		ans+=dp[n][n];
		printf("%d\n",ans);
	}
	return 0;
}
