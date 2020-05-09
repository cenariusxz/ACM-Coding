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

struct node{
	int x, y;
}nd[55*55];

int n, cnt;
char s[55][55], tmp[55][55];
int ans[105][105];	// 0 attack  1 not attack  -1 center

void solve(){
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			if(s[i][j] == 'o'){
				++cnt;
				nd[cnt].x = i;
				nd[cnt].y = j;
			}
			tmp[i][j] = '.';
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			if(s[i][j] != '.')continue;
			for(int p = 1 ; p <= cnt ; ++ p){
				int dx = i - nd[p].x, dy = j - nd[p].y;
				ans[n + dx][n + dy] = 1;
			}
		}
	}
	ans[n][n] = -1;
	for(int i = 1 ; i <= 2*n-1 ; ++ i){
		for(int j = 1 ; j <= 2*n-1 ; ++ j){
			if(ans[i][j])continue;
			int dx = i - n, dy = j - n;
			for(int p = 1 ; p <= cnt ; ++ p){
				int xx = nd[p].x + dx, yy = nd[p].y + dy;
				if(xx < 1 || xx > n || yy < 1 || yy > n)continue;
				tmp[xx][yy] = 'x';
			}
		}
	}
	for(int p = 1 ; p <= cnt ; ++ p)tmp[nd[p].x][nd[p].y] = 'o';
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			if(s[i][j] == tmp[i][j])continue;
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for(int i = 1 ; i <= 2*n-1 ; ++ i){
		for(int j = 1 ; j <= 2*n-1 ; ++ j){
			if(ans[i][j] == 0)putchar('x');
			if(ans[i][j] == 1)putchar('.');
			if(ans[i][j] == -1)putchar('o');
		}
		putchar('\n');
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i] + 1);
	solve();
	return 0;
}

