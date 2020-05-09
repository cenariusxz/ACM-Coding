// not a right answer

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 3e5 + 5;
const int maxm = 1e6 + 5;

int n, m;
char s[maxn];
int st[maxn], ed[maxn];

int get(int l, int r){return l >= r ? 0 : r - l;}

void solve(){
	memset(st, 0x3f, sizeof(st));
	memset(ed, -1, sizeof(ed));
	int ans = 0;
	for(int i = 1 ; s[i] ; ++ i){
		if(s[i] != '.')st[i] = i+1;
		else if(s[i-1] == '.')st[i] = st[i-1];
		else st[i] = i;
	}
	for(int i = n ; i >= 0 ; -- i){
		if(s[i] != '.')ed[i] = i-1;
		else if(s[i+1] == '.')ed[i] = ed[i+1];
		else ed[i] = i;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(s[i] != '.')continue;
		ans += get(st[i], ed[i]);
		i = ed[i];
	}
	while(m --){
		int x, res = ans;
		char c[5];
		scanf("%d%s", &x, c);
		if(s[x] == '.' && c[0] != '.')res = res - get(st[x], ed[x]) + get(st[x-1], x-1) + get(x+1, ed[x+1]);
		if(s[x] != '.' && c[0] == '.')res = res - get(st[x-1], ed[x-1]) - get(st[x+1], ed[x+1]) + get(st[x-1], ed[x+1]);
		printf("%d\n", res);
	}
}

int main(){
	scanf("%d%d%s", &n, &m, s+1);
	solve();
	return 0;
}

