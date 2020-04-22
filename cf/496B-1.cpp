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
char str[maxn];
string s, t, ans;

void solve(){
	for(int i = 1 ; i <= n ; ++ i)ans += '9';
	s = s + s;
	for(int i = 0 ; i < n ; ++ i){
		t = s.substr(i, n);
		int del = 10 - (t[0] - '0');
		for(int j = 0 ; j < n ; ++ j)t[j] = char((t[j] - '0' + del) % 10 + '0');
		if(t < ans)ans = t;
	}
	printf("%s\n", ans.c_str());
}

int main(){
	scanf("%d%s", &n, str);
	s = string(str);
	solve();
	return 0;
}

