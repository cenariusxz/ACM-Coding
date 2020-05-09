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

char s[maxn];

void solve(){
	int ans = 0;
	scanf("%s", s+1);
	int num = 0;
	for(int i = 1 ; s[i] ; ++ i){
		if(s[i] == 'R')num = 0;
		else ans = max(ans, ++num);
	}
	printf("%d\n", ans+1);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

