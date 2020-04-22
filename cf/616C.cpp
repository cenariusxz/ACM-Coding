#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 5;

int n, m;
char s[maxn][maxn], ans[maxn][maxn];
int id[maxn][maxn], num[maxm], cnt = 0;
int xx[4] = {0, 0, 1, -1}, yy[4] = {1, -1, 0, 0};

int dfs(int x, int y){
	id[x][y] = cnt;
	int sum = 1;
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = x + xx[i], dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
		if(s[dx][dy] == '*' || id[dx][dy] != -1)continue;
		sum += dfs(dx, dy);
	}
	return sum;
}

void solve(){
	memset(id, -1, sizeof(id));
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '.' && id[i][j] == -1){
				cnt++;
				num[cnt] = dfs(i, j);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '.'){
				ans[i][j] = '.';
				continue;
			}
			int sum = 1;
			for(int k = 0 ; k < 4 ; ++ k){
				int dx = i + xx[k], dy = j + yy[k];
				if(s[dx][dy] == '*')continue;
				bool flag = 0;
				for(int p = 0 ; p < k ; ++ p){
					int ddx = i + xx[p], ddy = j + yy[p];
					if(id[ddx][ddy] == id[dx][dy])flag = 1;
				}
				if(!flag)sum += num[id[dx][dy]];
			}
			ans[i][j] = sum % 10 + '0';
		}
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%s\n", ans[i]+1);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i]+1);
	solve();
	return 0;
}

