#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
ll dp[65];

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

void init(){
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	for(int i=4;i<=60;i++){
		dp[i]=dp[i-3]+1+dp[i-1];
	}
}

int main(){
	int n;
	init();
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",dp[n]);
	}
	return 0;
}
