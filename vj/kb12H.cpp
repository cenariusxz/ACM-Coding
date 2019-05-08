#include<stdio.h>
#include<string.h>
const int maxn=2e3+5;
int a[maxn],b[maxn];
int dp[maxn];

inline int min(int a,int b){return a<b?a:b;}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=2;i<=n;++i)scanf("%d",&b[i]);
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		dp[1]=a[1];
		for(int i=2;i<=n;++i){
			dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i]);
		}
		int hour=8+dp[n]/3600;
		int min=dp[n]%3600/60;
		int sec=dp[n]%60;
		bool f=0;
		if(hour>12){
			f=1;
			hour-=12;
		}
		if(hour<10)printf("0");
		printf("%d:",hour);
		if(min<10)printf("0");
		printf("%d:",min);
		if(sec<10)printf("0");
		printf("%d ",sec);
		if(f)printf("pm\n");
		else printf("am\n");
	}
	return 0;
}
