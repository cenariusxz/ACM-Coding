#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b
#define INF 0xFFFFFFF

int a[205],dp[35][205],w[205][205];

int main(){
	int n,m,c=0;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0||m!=0){
		int i,j,k,tmp,ans=INF;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(w,0,sizeof(w));
		for(i=n;i>=1;i--){
			a[i]=a[i]-a[1]+1;
		}
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				tmp=0;
				for(k=i;k<=j;k++){
					
					tmp+=min(a[k]-a[i],a[j]-a[k]);
				}
				w[i][j]=tmp;
			}
		}
/*		
		printf("\nw:\n");
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%3d",w[i][j]);
			}
			printf("\n");
		}
		printf("\n");
*/
	//	printf("min=%d\n",min(a[3]-a[2],a[2]-a[1]));

		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				dp[1][i]+=a[i]-a[j];
			}
		}
		for(j=2;j<=m;j++){
			for(i=j;i<=n;i++){
				dp[j][i]=INF;
				for(k=j-1;k<=i-1;k++){
					dp[j][i]=min(dp[j][i],dp[j-1][k]+w[k][i]);
				/*	
					if(t==0){
					printf("i=%d\nj=%d\nk=%d\ndp[j-1][k]=%d\nw(k,i)=%d\n",i,j,k,dp[j-1][k],w[k][i]);
					}
*/
					
				}
				
			}
		}
/*
		printf("\n");
		for(j=1;j<=m;j++){
			for(i=1;i<=n;i++){
				printf("%3d",dp[j][i]);
			}
			printf("\n");
		}
		printf("\n");
*/
		for(i=m;i<=n;i++){
			tmp=dp[m][i];
		//	printf("%d\n",tmp);
			for(j=i+1;j<=n;j++){
				tmp+=a[j]-a[i];
			}
			ans=min(ans,tmp);
		}
	//	printf("\n");
		printf("Chain %d\nTotal distance sum = %d\n\n",++c,ans);
	}
	return 0;
}
