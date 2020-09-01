#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll t, w[1005], num[1005];

inline ll min(ll a, ll b){return a < b ? a : b;}
inline ll max(ll a, ll b){return a > b ? a : b;}

ll solve(){
	if(t < m)return -1;
	ll ans = 0, sum = 0;
	int pos = 1;	// 上一轮用到 pos （pos-num[pos] ~ pos - 1） 
	for(int i = 1 ; i <= n ; ++ i){
		while(pos < i && w[pos] - 1 + t < w[i]){
			sum -= num[pos++];
		}
		ll tmp = sum;
		if(pos != i){
			tmp = tmp - num[pos] + min(num[pos], w[pos] + t - w[i]);
		}
		num[i] = max(0, m - tmp);
		ans += num[i];
		sum += num[i];
	}
	return ans;
}

int main(){
	scanf("%d%lld%d", &n, &t, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &w[i]);
	printf("%lld\n", solve());
	return 0;
}

