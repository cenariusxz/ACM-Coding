#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

ll a, b, c, d, ans = INF;
char s[4][4];

ll cal(ll a, ll b, int o){return s[o][0] == '+' ? a + b : a * b;}

ll min(ll a, ll b){return a < b ? a : b;}

void dfs3(ll a, ll b){
	ans = min(ans, cal(a, b, 3));
}

void dfs2(ll a, ll b, ll c){
	dfs3(cal(a, b, 2), c);
	dfs3(cal(a, c, 2), b);
	dfs3(cal(b, c, 2), a);
}

void dfs1(ll a, ll b, ll c, ll d){
	dfs2(cal(a, b, 1), c, d);
	dfs2(cal(a, c, 1), b, d);
	dfs2(cal(a, d, 1), b, c);
	dfs2(cal(b, c, 1), a, d);
	dfs2(cal(b, d, 1), a, c);
	dfs2(cal(c, d, 1), a, b);
}

int main(){
	scanf("%lld%lld%lld%lld%s%s%s", &a, &b, &c, &d, s[1], s[2], s[3]);
	dfs1(a, b, c, d);
	printf("%lld\n", ans);
	return 0;
}

