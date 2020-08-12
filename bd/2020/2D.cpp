#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, cnt, num[15], vis[15], sum[10], ans;
char s[8];

int cal(){
	int tmp = n - sum[1] - sum[2] - sum[3] - sum[4];
	return min(tmp, min(sum[1], min(sum[2], min(sum[3], sum[4]))));
}

void dfs(int t, int group, int pre){	// 定完 t 个， 正在 group 组，本组到上个为 pre
	if(t == cnt){
		if(group == 5)ans = max(ans, cal());
		return;
	}
	// 为group组再选一个 
	for(int i = pre + 1 ; i <= cnt ; ++ i){
		if(vis[i])continue;
		vis[i] = group;
		sum[group] += num[i];
		dfs(t+1, group, i);
		vis[i] = 0;
		sum[group] -= num[i];
	}
	if(group == 5)return;
	// 为 group+1组选第一个 
	for(int i = 1 ; i <= cnt ; ++ i){
		if(vis[i])continue;
		vis[i] = group+1;
		sum[group+1] = num[i];
		dfs(t+1, group+1, i);
		vis[i] = 0;
		sum[group+1] -= num[i];
		break;
	}
}

int solve(){
	scanf("%d", &n);
	memset(num, 0, sizeof(num));
	memset(vis, 0, sizeof(vis));
	memset(sum, 0, sizeof(sum));
	ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s", s);
		num[s[4] - '0' + 1] ++;
	}
	sort(num + 1, num + 1 + 10, greater<int>());
	for(int i = 1 ; i <= 10 ; ++ i){
		if(num[i])cnt = i;
	}
	if(cnt < 5)return n;
	vis[1] = 1; sum[1] = num[1];
	dfs(1, 1, 1);
	return n - ans;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)printf("%d\n", solve());
	return 0;
}

