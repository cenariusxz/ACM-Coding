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
int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, 1, -1};
int vis[505][505];

bool solve(){
	int cx = 0, cy = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '.')continue;
			bool f = 1;
			for(int k = 0 ; k < 4 ; ++ k){
				int dx = i + xx[k], dy = j + yy[k];
				if(s[dx][dy] != '*')f = 0;
			}
			if(f)cx = i, cy = j;
		}
	}
	if(cx == 0)return 0;
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = cx, dy = cy;
		while(s[dx][dy] == '*'){
			vis[dx][dy] = 1;
			dx += xx[i];
			dy += yy[i];
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '*' && vis[i][j] == 0)return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i] + 1);
	if(solve())printf("YES\n");
	else printf("NO\n");
	return 0;
}

