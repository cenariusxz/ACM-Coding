#include<stdio.h>
#include<string.h>

int sum[305],a[305];
int dp[305][305];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(sum,0,sizeof(sum));
	memset(dp,0,sizeof(dp));
	int i,j,k;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
		bool f=1;
			for(k=0;k<=(j-i)/2&&f;k++){
				if(a[i+k]!=a[j-k]){
					f=0;
				}
			}
		if(f)dp[i][j]=sum[j]-sum[i-1];
		}
	}
	for(i=1;i<=m;i++){
		int a,b;
		int ans=0;
		scanf("%d%d",&a,&b);
		for(j=a;j<=b;j++){
			for(k=j;k<=b;k++){
				ans+=dp[j][k];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
