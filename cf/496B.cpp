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

int n, s[maxn], t[maxn], ans[maxn];

void solve(){
	for(int i = 1 ; i <= n ; ++ i)ans[i] = 9;
	for(int i = 1 ; i <= n ; ++ i)s[n+i] = s[i];
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j)t[j] = s[i + j - 1];
		int del = 10 - t[1];
		for(int j = 1 ; j <= n ; ++ j)t[j] = (t[j] + del) % 10;
		bool flag = 0;
		for(int j = 1 ; j <= n ; ++ j){
			if(t[j] == ans[j])continue;
			if(t[j] < ans[j])flag = 1;
			break;
		}
		if(flag)memcpy(ans, t, sizeof(ans));
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%d", ans[i]);
	printf("\n");
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%1d", &s[i]);
	solve();
	return 0;
}

