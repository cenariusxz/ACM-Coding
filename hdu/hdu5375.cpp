#include<stdio.h>
#include<string.h>
const int maxm=2e5+5;
const int INF=0x3f3f3f3f;

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int max(int a,int b){
	return a>b?a:b;
}

int a[maxm];
int dp[maxm][2];
char s[maxm];

int main(){
	int T=read();
	int cnt=0;
	while(T--){
		int i;
		scanf("%s",s+1);
		int n=strlen(s+1);
		memset(dp,-1,sizeof(dp));
		for(i=1;i<=n;i++)a[i]=read();
		dp[1][0]=dp[1][1]=-INF;
		if(s[1]=='1')dp[1][1]=a[1];
		else if(s[1]=='0')dp[1][0]=0;
		else if(s[1]=='?'){
			dp[1][1]=a[1];
			dp[1][0]=0;
		}
		for(i=2;i<=n;i++){
			dp[i][0]=dp[i][1]=-INF;
			if(s[i]=='1'){
				dp[i][1]=max(dp[i-1][0]+a[i],dp[i-1][1]);
			}
			else if(s[i]=='0'){
				dp[i][0]=max(dp[i-1][1]+a[i],dp[i-1][0]);
			}
			else if(s[i]=='?'){
				dp[i][1]=max(dp[i-1][0]+a[i],dp[i-1][1]);
				dp[i][0]=max(dp[i-1][1]+a[i],dp[i-1][0]);	
			}
		}
		printf("Case #%d: %d\n",++cnt,max(dp[n][0],dp[n][1]));
	}
	return 0;
}
