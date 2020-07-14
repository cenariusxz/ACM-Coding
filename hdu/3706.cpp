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

int n;
ll a, b;

deque<pair<int, ll> > qmax;

void solve(){
	while(!qmax.empty())qmax.pop_back();
	ll tmp = 1, ans = 1;
	for(int i = 1 ; i <= n ; ++ i){
		tmp = tmp * a % b;
		while(!qmax.empty() && qmax.back().second >= tmp)qmax.pop_back();
		qmax.PB(MP(i, tmp));
		if(!qmax.empty() && qmax.front().first <= i-a)qmax.pop_front();
		ans = ans * qmax.front().second % b;
	}
	printf("%lld\n", ans);
}

int main(){
	while(scanf("%d%lld%lld", &n, &a, &b)!=EOF)solve();
	return 0;
}

