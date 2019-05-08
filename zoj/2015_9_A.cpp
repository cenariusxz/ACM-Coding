#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

char s[100005];
char ss[105];
int num[105];
ll dp[105][105][3];
int n;

void get(){
	memset(dp,0,sizeof(dp));
	n=0;
	int f=0;
	for(int i=1;s[i];++i){
		if(s[i]>='0'&&s[i]<='9')f=1;
		else if(s[i]>='a'&&s[i]<='z')f=-1;
		else{
			n++;
			num[n]=f;
			ss[n]=s[i];
		}
	}
	num[++n]=f;
	for(int i=1;i<=n;++i){
		dp[i][i][0]=1;
		if(num[i]==1)dp[i][i][1]=1;
		else dp[i][i][2]=1;
	}
}

void solve(int l,int r){
	if(dp[l][r][0])return;
	dp[l][r][0]=1;
	for(int i=l;i<r;++i){
		solve(l,i);
		solve(i+1,r);
		if(ss[i]=='*'){
			dp[l][r][2]=(dp[l][r][2]+dp[l][i][1]*dp[i+1][r][2]%mod+dp[l][i][2]*dp[i+1][r][1]%mod)%mod;
			dp[l][r][1]=(dp[l][r][1]+dp[l][i][1]*dp[i+1][r][1]%mod)%mod;
		}
		else if(ss[i]=='.')dp[l][r][1]=(dp[l][r][1]+dp[l][i][2]*dp[i+1][r][2]%mod)%mod;
		else if(ss[i]=='^')dp[l][r][2]=(dp[l][r][2]+dp[l][i][2]*dp[i+1][r][2]%mod)%mod;
		else if(ss[i]=='!'){
			dp[l][r][2]=(dp[l][r][2]+dp[l][i][1]*dp[i+1][r][1]%mod+dp[l][i][1]*dp[i+1][r][2]%mod+dp[l][i][2]*dp[i+1][r][1]%mod)%mod;
			dp[l][r][1]=(dp[l][r][1]+dp[l][i][2]*dp[i+1][r][2]%mod)%mod;
		}
	}
	return;
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			scanf("%s",s+1);
			get();
			solve(1,n);
			cout<<(dp[1][n][1]+dp[1][n][2])%mod<<endl;
		}
	}
	return 0;
}
