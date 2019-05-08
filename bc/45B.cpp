#include<stdio.h>
#include<string.h>

int a[1005],num[1005][1005],n,sum[1005][1005];
int main(){
	int q;
	while(scanf("%d%d",&n,&q)!=EOF){
		int i,j;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(num,0,sizeof(num));
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(a[j]<a[i]){
					num[i][j]=num[i][j-1]+1;
				}
				else num[i][j]=num[i][j-1];
			}
		}
		memset(sum,0,sizeof(sum));
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				sum[j][i]=sum[j-1][i]+num[j][i];
			}
		}
		for(i=1;i<=q;i++){
			int l,r;
			int ans=0;
			scanf("%d%d",&l,&r);
			ans=sum[r][r]-sum[l-1][r];
			printf("%d\n",ans);
		}
	}
	return 0;
}
