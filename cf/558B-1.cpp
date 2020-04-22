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

int n, l[maxm], r[maxm], cnt[maxm];

void solve(){
	memset(l, 0x3f, sizeof(l));
	memset(r, -1, sizeof(r));
	for(int i = 1 ; i <= n ; ++ i){
		int a; scanf("%d", &a);
		cnt[a] ++;
		l[a] = min(l[a], i);
		r[a] = i;
	}
	int ansid = 0;
	for(int i = 1 ; i <= 1000000 ; ++ i){
		if(cnt[i] > cnt[ansid])ansid = i;
		else if(cnt[i] == cnt[ansid] && (r[i] - l[i]) < (r[ansid] - l[ansid]))ansid = i;
	}
	printf("%d %d\n", l[ansid], r[ansid]);
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}

