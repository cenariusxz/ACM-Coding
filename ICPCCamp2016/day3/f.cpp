#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
long long dp[410 * 401][401];
long long sum[401 * 401][401];
const long long mod = 1e9 + 7;

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; ++i){
		if(k - i >= 0){
			sum[k - i][i] = 1;
		}
	}
	int top = min(k,n * (n - 1) / 2);
	for(int i = 1; i <= n; ++i){
		int j1 = top - i * (i - 1) / 2;
		int j2 = (n + i + 1) * (n - i) / 2;
		for(int j = j2; j >= j1; --j){

		}
	}
	return 0;
}
