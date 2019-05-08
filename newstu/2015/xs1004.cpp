#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

ll dp[105][10];
ll sum[105][10];

void init(){
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	for(int i=0;i<=9;++i)dp[1][i]=1;
	sum[1][0]=1;
	for(int i=1;i<=9;++i)sum[1][i]=sum[1][i-1]+dp[1][i];
	for(int i=2;i<=n;++i){
		
	}
}

int main(){
	
}
