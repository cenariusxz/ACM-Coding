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

map<int, int>M;
int dp[maxn], pre[maxn], a[maxn], n;
int res[maxn], cnt;

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	int ans = 0, ansid = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int preid = M[a[i] - 1];
		pre[i] = preid;
		dp[i] = dp[preid] + 1;
		M[a[i]] = i;
		if(dp[i] > ans)ans = dp[i], ansid = i;
	}
	printf("%d\n", ans);
	int last = ansid;
	while(last != 0){
		res[++cnt] = last;
		last = pre[last];
	}
	for(int i = cnt ; i >= 1 ; -- i)printf("%d ", res[i]);
	printf("\n");
	return 0;
}

