#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int n, m, a[405][405];
int cnt, id[405][405], size[maxn];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};

int dfs(int x, int y){
	int sum = 1;
	id[x][y] = cnt;
	for(int i = 0 ; i < 4 ; ++ i){
		int dx = x + xx[i], dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m || !a[dx][dy] || id[dx][dy])continue;
		sum += dfs(dx, dy);
	}
	return sum;
}

int main(){
	scanf("%d%d", &n, &m);
	int sum = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(a[i][j] && !id[i][j]){
				++ cnt;
				size[cnt] = dfs(i, j);
			}
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(a[i][j])continue;
			int que[5], c = 0;
			for(int k = 0 ; k < 4 ; ++ k){
				int dx = i + xx[k], dy = j + yy[k];
				if(dx < 1 || dx > n || dy < 1 || dy > m || !a[dx][dy])continue;
				que[++c] = id[dx][dy];
			}
			sort(que+1, que+1+c);
			c = unique(que+1, que+1+c) - (que+1);
			int tmp = 0;
			for(int k = 1 ; k <= c ; ++ k)tmp += size[que[k]];
			if(tmp == sum)ans = sum;
			else ans = max(ans, tmp + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}

