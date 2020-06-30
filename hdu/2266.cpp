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

char s[15];
ll n;
int ans, len, sign[15];

void dfs(int t){
	if(t == len-1){
		ll sum = 0, num = 0;
		int si = 1;
		for(int i = 1 ; i <= len ; ++ i){
			num = num * 10 + s[i] - '0';
			if(sign[i]){
				sum += si * num;
				num = 0;
				si = sign[i];
			}
		}
		if(sum == n)ans ++;
		return;
	}
	sign[t+1] = 0;
	dfs(t+1);
	sign[t+1] = 1;
	dfs(t+1);
	sign[t+1] = -1;
	dfs(t+1);
}

int solve(){
	ans = 0;
	len = strlen(s+1);
	sign[len] = 1;
	dfs(0);
	return ans;
}

int main(){
	while(scanf("%s%lld", s+1, &n)!=EOF)printf("%d\n", solve());
	return 0;
}

