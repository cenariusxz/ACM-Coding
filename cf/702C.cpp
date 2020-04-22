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

int n, m, a[maxn], b[maxn]; 

bool check(int dis){
	int pos = 1;	// 满足上一个城市的塔
	for(int i = 1 ; i <= n ; ++ i){
		while(a[i] - b[pos] > dis && pos + 1 <= m)pos++;
		if(abs(a[i] - b[pos]) > dis)return 0;
	}
	return 1;
}

void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= m ; ++ i)scanf("%d", &b[i]);
	int l = 0, r = INF+INF, ans = INF+INF;
	while(l <= r){
		int mid = l + ((r - l) >> 1);
		if(check(mid))ans = min(ans, mid), r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d", &n, &m);
	solve();
	return 0;
}


