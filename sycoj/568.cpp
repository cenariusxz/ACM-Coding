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

int s[15][15];
int row[15][15];
int col[15][15];
int grid[15][15];
bool done = 0;
int ans = -1;
struct line{
	int x, num;
	bool operator < (const line a)const{
		return num < a.num;	
	}
}ln[15];

int solve(){
	int res = 0;
	for(int i = 1 ; i <= 9 ; ++ i){
		for(int j = 1 ; j <= 9 ; ++ j){
			int dis = min(min(j,10-j), min(i,10-i));
			res += s[i][j] * (dis + 5);
		}
	}
	return res;
}

void dfs(int id,int y){
	if(id == 9 && y == 9){
		ans = max(ans, solve());
		return;
	}
	y++;
	if(y == 10)id++, y=1;
	int x = ln[id].x;
	if(s[x][y])dfs(id,y);
	else{
		for(int i = 1 ; i <= 9 ; ++ i){
			if(row[x][i])continue;
			if(col[y][i])continue;
			if(grid[(x-1)/3*3+(y-1)/3][i])continue;
			s[x][y] = i;
			row[x][i] = 1;
			col[y][i] = 1;
			grid[(x-1)/3*3+(y-1)/3][i] = 1;
			dfs(id,y);
			if(done)return;
			s[x][y] = 0;
			row[x][i] = 0;
			col[y][i] = 0;
			grid[(x-1)/3*3+(y-1)/3][i] = 0;
		}
	}
}

int main(){
	for(int i = 1 ; i <= 9 ; ++ i){
		ln[i].x = i;
		ln[i].num = 0;
		for(int j = 1 ; j <= 9 ; ++ j){
			scanf("%d",&s[i][j]);
			if(s[i][j]){
				row[i][s[i][j]] = 1;
				col[j][s[i][j]] = 1;
				grid[(i-1)/3*3+(j-1)/3][s[i][j]] = 1;
			}
			else ln[i].num ++;
		}
	}
	sort(ln + 1, ln + 1 + 9);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}


