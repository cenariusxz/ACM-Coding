#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int n,m,num[105],sum[105],pw9[10];
int ans0 = INF, ans1 = -1;
int stx,edx;

int getSum(int l,int r){
	return ((sum[r] - sum[l-1]) % 10 + 10) % 10;
}

void dfs(int pre, int t, int res){
	if(t == m-1){
		int ans = res * getSum(pre+1,edx);
		if(ans < ans0)ans0 = ans;
		if(ans > ans1)ans1 = ans;
		return;
	}
	for(int now = pre+1 ; now <= edx+t-m+1 ; ++ now){
		int tmp = res * getSum(pre+1,now);
		if(ans0==0 && tmp*pw9[m-t-1] <= ans1)continue;
		dfs(now,t+1,tmp);
	}
}

int main(){
	pw9[0] = 1;
	for(int i = 1 ; i <= 10 ; ++ i)pw9[i] = pw9[i-1]*9;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d",&num[i]);
		num[n+i] = num[i];
	}
	for(int i = 1 ; i <= 2 * n ; ++ i){
		sum[i] = sum[i-1] + num[i];
		sum[i] = (sum[i] % 10 + 10) % 10;
	}

	for(stx = 1 ; stx <= n ; ++ stx){
		edx = stx + n - 1;
		dfs(stx-1, 0, 1);
	}

	printf("%d\n%d\n",ans0,ans1);
	return 0;
}
