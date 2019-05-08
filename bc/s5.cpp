#include<stdio.h>
#include<string.h>

int dp[205][205],a[205],ans[205];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int n,m;
		scanf("%d%d",&n,&m);
		int i,j,k;
		for(i=1;i<=m;i++)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[1][0]=1;
		for(i=1;i<n;i++){
			for(j=0;j<n;j++){
				if(dp[i][j]){
					for(k=1;k<=m;k++){
						dp[i+1][(j+a[k])%(i+1)]=1;
					}
				}
			}
		}
		int cnt=0;
		for(i=0;i<n;i++){
			if(dp[n][i])ans[++cnt]=i+1;
		}
		printf("%d\n",cnt);
		for(i=1;i<=cnt;i++){
			printf("%d",ans[i]);
			if(i==cnt)printf("\n");
			else printf(" ");
		}

	}
	return 0;
}
