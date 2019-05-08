#include <stdio.h>
#include <string.h>
#include <algorithm>
typedef long long ll;
using namespace std;

int T,len;
ll A,B;
int s[30];
ll dp[30][2][10];

ll Dfs(int p,int f,int mo){
	if(p > len){
		if(mo == 0) return 1;
		return 0;
	}
	if(dp[p][f][mo] != -1) return dp[p][f][mo];
	int top = f ? 9 : s[p];
	ll res = 0;
	for(int i = 0; i <= top; ++i){
		res += Dfs(p + 1,f | (i < s[p]),(mo + i) % 10);
	}
	return dp[p][f][mo] = res;
}

ll Solve(ll v){
	if(v == -1) return 0;
	memset(dp,-1,sizeof(dp));
	len = 0;
	while(v){
		s[++len] = v % 10;
		v /= 10;
	}
	for(int i = 1; i <= len / 2; ++i) swap(s[i],s[len + 1 - i]);
	return Dfs(1,0,0);
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%lld%lld",&A,&B);
		printf("Case #%d: %lld\n",tt,Solve(B) - Solve(A - 1));		
	}
	return 0;
}
