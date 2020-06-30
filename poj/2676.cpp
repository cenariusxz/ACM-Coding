#include <stdio.h>
#include <string.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int a[15][15];
int visr[15][15], visc[15][15], visb[15][15];
bool f;

void dfs(int x, int y){
	if(x == 8 && y == 8){
		for(int i = 0 ; i < 9 ; ++ i){
			for(int j = 0 ; j < 9 ; ++ j){
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
		f = 1;
		return;
	}
	if(y == 8)++ x, y = 0;
	else ++ y;
	if(a[x][y]){
		dfs(x, y);
		return;
	}
	for(int i = 1 ; i <= 9 ; ++ i){
		if(visr[x][i] || visc[y][i] || visb[x/3*3+y/3][i])continue;
		visr[x][i] = 1;
		visc[y][i] = 1;
		visb[x/3*3+y/3][i] = 1;
		a[x][y] = i;
		dfs(x, y);
		if(f)return;
		visr[x][i] = 0;
		visc[y][i] = 0;
		visb[x/3*3+y/3][i] = 0;
		a[x][y] = 0;
	}
}

void solve(){
	f = 0;
	for(int i = 0 ; i < 9 ; ++ i){
		for(int j = 0 ; j < 9 ; ++ j){
			scanf("%1d", &a[i][j]);
		}
	}
	memset(visr, 0, sizeof(visr));
	memset(visc, 0, sizeof(visc));
	memset(visb, 0, sizeof(visb));
	for(int i = 0 ; i < 9 ; ++ i){
		for(int j = 0 ; j < 9 ; ++ j){
			if(a[i][j] == 0)continue;
			visr[i][ a[i][j] ] = 1;
			visc[j][ a[i][j] ] = 1;
			visb[ i/3*3 + j/3 ][ a[i][j] ] = 1;
		}
	}
	dfs(0, -1);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve(); 
	return 0;
}

