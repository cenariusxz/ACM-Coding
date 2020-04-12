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

int n;
char s[maxn];

void solve(){
	for(int i = 2 ; s[i] ; ++ i){
		if(s[i] != s[i-1]){
			printf("YES\n%c%c\n", s[i-1], s[i]);
			return;
		}
	}
	printf("NO\n");
	return;
}

int main(){
	scanf("%d%s", &n, s+1);
	solve();
	return 0;
}


