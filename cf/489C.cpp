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

int m, s;
int ans[105];

void solve(){
	int t = s;
	memset(ans, 0, sizeof(ans));
	ans[1] = 1; t--;
	for(int i = m ; i >= 1 ; -- i){
		int del = min(9 - ans[i], t);
		ans[i] += del; t -= del;
	}
	for(int i = 1 ; i <= m ; ++ i)printf("%d", ans[i]);
	printf(" ");
	memset(ans, 0, sizeof(ans));
	t = s;
	for(int i = 1 ; i <= m ; ++ i){
		int del = min(9 - ans[i], t);
		ans[i] += del; t -= del;
	}
	for(int i = 1 ; i <= m ; ++ i)printf("%d", ans[i]);
	printf("\n");
}

int main(){
	scanf("%d%d", &m, &s);
	if(m == 1 && s == 0)printf("0 0\n");
	else if(s == 0 || s > 9*m)printf("-1 -1\n");
	else solve();
	return 0;
}


