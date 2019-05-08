#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int num[maxn];
int n;
int dp[maxn],ans;

void solve1(){
	ans = 1;
	dp[0] = INF;
	dp[ans] = num[1];
	for(int i = 2 ; i <= n ; ++ i){
		int l = 0 , r = ans;
		int res = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(dp[mid] >= num[i]){
				res = max(mid,res);
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if(res == ans)ans++;
		dp[res+1] = num[i];
	}
	printf("%d\n",ans);
}

void solve2(){
	ans = 1;
	dp[0] = -1;
	dp[ans] = num[1];
	for(int i = 2 ; i <= n ; ++ i){
		int l = 0 , r = ans;
		int res = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(dp[mid] < num[i]){
				res = max(mid,res);
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if(res == ans)ans++;
		dp[res+1] = num[i];
	}
	printf("%d\n",ans);
}

int main(){
	n = 0;
	while(scanf("%d",&num[n+1])!=EOF)++n;
	solve1();
	solve2();
	return 0;
}
