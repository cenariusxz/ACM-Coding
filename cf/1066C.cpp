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

int q, pos[maxm];

void solve(){
	scanf("%d", &q);
	int left = maxn, right = maxn-1;
	while(q--){
		char s[5];
		int id;
		scanf("%s%d", s, &id);
		if(s[0] == 'L')pos[id] = --left;
		if(s[0] == 'R')pos[id] = ++right;
		if(s[0] == '?')printf("%d\n", min(right - pos[id], pos[id] - left));
	}
}

int main(){
	solve();
	return 0;
}

