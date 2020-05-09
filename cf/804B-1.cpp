#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;

ll num[maxn];
char s[maxn];

void init(){
	num[1] = 1;
	for(int i = 2 ; i < maxn ; ++ i){
		num[i] = 2 * num[i-1] + 1;
		if(num[i] >= mod)num[i] -= mod;
	}
}

void solve(){
	int cnt = 0;
	ll ans = 0;
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == 'a')cnt++;
		else{
			ans += num[cnt];
			if(ans >= mod)ans -= mod;
		}
	}
	printf("lld\n", ans);
}

int main(){
	scanf("%s", s);
	solve();
	return 0;
}

