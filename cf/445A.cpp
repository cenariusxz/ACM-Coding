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

int n, m;
char s[105][105];

void solve(){
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '-')continue;
			s[i][j] = ((i + j) % 2) ? 'B' : 'W';
		}
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%s\n", s[i]+1);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i]+1);
	solve();
	return 0;
}

