#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

struct node{
	ll cnt, sum, sum2;
	node(){}
	node(ll _cnt, ll _sum, ll _sum2):cnt(_cnt), sum(_sum), sum2(_sum2){}
}dp[20][10][10];
int vis[20][10][10];
int num[20];
ll pow10[20];

node dfs(int t, int p1, int p2, int flag){
	// 高位到低位当前要选第t位（len~1），数位和%7=p1，数%7=p2，flag是否受限 
	// 返回后续选完满足条件的dp答案 
	if(t == 0){
		if(p1 == 0 || p2 == 0)return node(0,0,0);
		else return node(1,0,0); 
	}
	if(!flag && vis[t][p1][p2])return dp[t][p1][p2];
	node ans = node(0,0,0);
	int l = 0, r = flag ? num[t] : 9;
	for(int i = l ; i <= r ; ++ i){
		if(i == 7)continue;
		node res = dfs(t-1, (p1+i) % 7, (p2*10 + i) % 7, flag && i == r);
		ans.cnt = (ans.cnt + res.cnt) % mod;
		
		ans.sum = (ans.sum + res.sum + i*pow10[t-1] % mod * res.cnt % mod) % mod;
		
		ll tmp1 = res.cnt * (i*pow10[t-1]%mod) % mod * (i*pow10[t-1]%mod) % mod;
		ll tmp2 = 2 * (i*pow10[t-1]%mod) % mod * res.sum % mod;
		ll tmp3 = res.sum2;
		ans.sum2 = (ans.sum2 + tmp1 + tmp2 + tmp3) % mod;
	}
	if(!flag)vis[t][p1][p2] = 1, dp[t][p1][p2] = ans;
	return ans;
}

ll get(ll x){
	int cnt = 0;
	while(x){
		num[++cnt] = x % 10;
		x /= 10;
	}
	return dfs(cnt, 0, 0, 1).sum2;
}

void solve(){
	ll l,r;
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",((get(r) - get(l-1)) % mod + mod) % mod);
}

int main(){
	int T;
	scanf("%d", &T);
	pow10[0] = 1;
	for(int i = 1 ; i <= 19 ; ++ i)pow10[i] = pow10[i-1] * 10 % mod;
	while(T--)solve();
	return 0;
}

