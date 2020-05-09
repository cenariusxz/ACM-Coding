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

int n, m, k;
char s[305][305];

void solve(){
	int cnt = 0;
	for(int r = 1 ; 2*r <= n ; ++ r){
		for(int i = 1 + r ; i + r <= n ; ++ i){
			for(int j = 1 + r ; j + r <= m ; ++ j){
				if(s[i][j] == '.')continue;
				if(s[i-r][j] == '*' && s[i+r][j] == '*'&& s[i][j-r] == '*' && s[i][j+r] == '*')cnt++;
				if(cnt == k){
					printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", i, j, i-r, j, i+r, j, i, j-r, i, j+r);
					return;
				}
			}
		}
	}
	printf("-1\n");
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i] + 1);
	solve();
	return 0;
}

