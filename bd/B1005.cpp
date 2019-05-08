#include<stdio.h>
#include<string.h>

int dp[100005],a[100005];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]-=i;
		}
		int ans=0;
		dp[++ans]=a[1];
		for(i=2;i<=n;i++){
			int low,high,mid;
			low=1;
			high=ans;
			while(low<=high){
				mid=(low+high)/2;
				if(dp[mid]<=a[i])low=mid+1;
				else high=mid-1;
			}
			dp[low]=a[i];
			if(low>ans)ans++;
		}	
		printf("Case #%d:\n%d\n",q,n-ans);
	}
	return 0;
}
