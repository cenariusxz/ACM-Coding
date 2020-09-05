#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

int n, a[maxn], g[maxn], dp[maxn];

int solve(int cnt){
	if(!cnt)return 0;
	int ans = 0;
	dp[++ans] = g[1];
	for(int i = 2 ; i <= cnt ; ++ i){
		int l = 1, r = ans, res = 0;
		while(l <= r){
			int m = (l + r) >> 1;
			if(dp[m] <= g[i])l = m + 1, res = max(res, m);
			else r = m - 1;
		}
		dp[res + 1] = g[i];
		if(res + 1 > ans)ans++;
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	a[n+1] = INF;
	int mx = 0, cnt = 0, ans = 0;
	for(int i = 1 ; i <= n + 1 ; ++ i){
		if(a[i] > mx){
			ans = max(ans, solve(cnt));
			cnt = 0;
			mx = a[i];
		}
		else g[++cnt] = a[i];
	}
	printf("%d\n", ans);
	return 0;
}
