#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

char s[15][15];
int row[15][15];
int col[15][15];
int grid[15][15];
bool done = 0;

void dfs(int x,int y){
	if(x == 9 && y == 9){
		done = 1;
		for(int i = 1 ; i <= 9 ; ++ i)printf("%s\n",s[i]+1);
		return;
	}
	y++;
	if(y == 10)x++, y=1;
	if(s[x][y] != '?')dfs(x,y);
	else{
		for(int i = 1 ; i <= 9 ; ++ i){
			if(row[x][i])continue;
			if(col[y][i])continue;
			if(grid[(x-1)/3*3+(y-1)/3][i])continue;
			s[x][y] = '0' + i;
			row[x][i] = 1;
			col[y][i] = 1;
			grid[(x-1)/3*3+(y-1)/3][i] = 1;
			dfs(x,y);
			if(done)return;
			s[x][y] = '?';
			row[x][i] = 0;
			col[y][i] = 0;
			grid[(x-1)/3*3+(y-1)/3][i] = 0;
		}
	}
}

int main(){
	for(int i = 1 ; i <= 9 ; ++ i)scanf("%s",s[i] + 1);
	for(int i = 1 ; i <= 9 ; ++ i){
		for(int j = 1 ; j <= 9 ; ++ j){
			if(s[i][j] == '?')continue;
			row[i][s[i][j] - '0'] = 1;
			col[j][s[i][j] - '0'] = 1;
			grid[(i-1)/3*3+(j-1)/3][s[i][j] - '0'] = 1;
		}
	}
	dfs(1,0);
	return 0;
}


