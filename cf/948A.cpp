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
char s[505][505];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};

void solve(){
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '.')s[i][j] = 'D';
			if(s[i][j] != 'S')continue;
			for(int k = 0 ; k < 4 ; ++ k){
				int dx = i + xx[k], dy = j + yy[k];
				if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
				if(s[dx][dy] == 'W'){
					printf("No\n");
					return;
				}
			}
		}
	}
	printf("Yes\n");
	for(int i = 1 ; i <= n ; ++ i)printf("%s\n", s[i]+1);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i] + 1);
	solve();
	return 0;
}

