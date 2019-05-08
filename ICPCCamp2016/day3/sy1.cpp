#include <stdio.h>
#include <string.h>

int dp[80000][410];

int Solve(int k,int j){
	if(dp[k][j]) return dp[k][j];
	int res = 0;
	int top = k > 10 ? 10 : k;
	for(int i = j; i <= top; ++i){
		res += Solve(k - i,i);
	}
	return dp[k][j] = res;
}

int main(){
	printf("%d\n",Solve(20,1));
	return 0;
}
