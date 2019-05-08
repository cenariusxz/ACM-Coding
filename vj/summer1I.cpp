#include<stdio.h>
#include<string.h>
int a[200005];
int dp[200005];
int dp1[200005],dp2[200005];

int main(){
	freopen("improvements.in","r",stdin);
	freopen("improvements.out","w",stdout);
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		int b;
		scanf("%d",&b);
		a[b]=i;
	}
	int ans1=0;
	memset(dp,0,sizeof(dp));
	dp[++ans1]=a[1];
	dp1[1]=1;
	for(i=2;i<=n;i++){
		int l=1,r=ans1;
		while(l<=r){
			int mid=l+((r-l)>>1);
			if(dp[mid]<a[i])l=mid+1;
			else r=mid-1;
		}
		dp[l]=a[i];
		dp1[i]=l;
		if(l>ans1)ans1++;
	}
	int ans2=0;
	memset(dp,0,sizeof(dp));
	dp[++ans2]=a[n];
	dp2[n]=1;
	for(i=2;i<=n;i++){
		int l=1,r=ans2;
		while(l<=r){
			int mid=l+((r-l)>>1);
			if(dp[mid]<a[n-i+1])l=mid+1;
			else r=mid-1;
		}
		dp[l]=a[n-i+1];
		dp2[n-i+1]=l;
		if(l>ans2)ans2++;
	}
	int maxx=0;
/*	for(i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	for(i=1;i<=n;i++)printf("%d ",dp1[i]);
	printf("\n");
	for(i=1;i<=n;i++)printf("%d ",dp2[i]);
	printf("\n");
*/	for(i=1;i<=n;i++){
		if(dp1[i]+dp2[i]-1>maxx)maxx=dp1[i]+dp2[i]-1;
	}
	printf("%d\n",maxx);
	return 0;
}
