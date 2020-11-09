#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 4e5 + 5;
const int maxm = 1e6 + 6;

struct node{
	int t, l, r, c;
	bool operator < (const node x)const{
		if(l == x.l)return r < x.r;
		return l < x.l;
	}
}nd[maxn];

inline ll max(ll a, ll b){return a > b ? a : b;}

int n, m, a[2][maxn];
ll sum[2][maxn], smax[maxn], dp[maxn];
vector<int> v[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[0][i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[1][i]);
	for(int i = 1 ; i <= n ; ++ i)sum[0][i] = sum[0][i-1] + a[0][i];
	for(int i = 1 ; i <= n ; ++ i)sum[1][i] = sum[1][i-1] + a[1][i];
	for(int i = 1 ; i <= n ; ++ i)smax[i] = smax[i-1] + max(a[0][i], a[1][i]);
	for(int i = 1 ; i <= m ; ++ i)scanf("%d%d%d%d", &nd[i].t, &nd[i].l, &nd[i].r, &nd[i].c);
	for(int i = 1 ; i <= m ; ++ i)nd[i].t--;
	sort(nd + 1 , nd + 1 + m);
	// for(int i = 1 ; i <= m ; ++ i)v[nd[i].r].PB(i);
	ll ans = smax[n];
	//for(int i = 0 ; i <= n ; ++ i)printf("%lld ", smax[i]);
	//printf("\n");
	for(int i = 1 ; i <= m ; ++ i){
		int t = nd[i].t, l = nd[i].l, r = nd[i].r, c = nd[i].c;
		dp[i] = smax[l-1] + (sum[t][r] - sum[t][l-1]) + c;
		//printf("i: %d, dp: %lld\n", i, dp[i]);
		//printf("%d smax:%lld sumr:%lld suml-1:%lld c:%lld %lld\n", r, smax[l-1], sum[t][r], sum[t][l-1], c, dp[i]);
		for(int j = 1 ; j < i ; ++ j){
			if(nd[j].r < l){
				ll tmp = dp[j] + smax[l-1] - smax[nd[j].r] + (sum[t][r] - sum[t][l-1]) + c;
				if(tmp > dp[i])dp[i] = tmp;
			}
			if(nd[j].r >= l && nd[j].t == t){
				ll tmp = dp[j] + sum[t][r] - sum[t][nd[j].r] + c;
				if(tmp > dp[i])dp[i] = tmp;
			}
		}
		//printf("%d %lld\n", r, dp[i]);
		//printf("i: %d, dp: %lld %lld\n", i, dp[i], dp[i] + smax[n] - smax[r]);
		ans = max(ans, dp[i] + smax[n] - smax[r]);
	}
	printf("%lld\n", ans);
	return 0;
}


