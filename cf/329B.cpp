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
	int x, y, t;
};

int r, c;
char s[1005][1005];
int sx, sy, tx, ty;
int step[1005][1005];
int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, 1, -1};

void bfs(){
	memset(step, 0x3f, sizeof(step));
	queue<node>q;
	q.push(node{sx, sy, 1});
	step[sx][sy] = 1;
	while(!q.empty()){
		node u = q.front(); q.pop();
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i], dy = u.y + yy[i];
			if(dx < 1 || dx > r || dy < 1 || dy > c || step[dx][dy] != INF || s[dx][dy] == 'T')continue;
			q.push(node{dx, dy, u.t + 1});
			step[dx][dy] = u.t + 1;
		}
	}
}

void solve(){
	for(int i = 1 ; i <= r ; ++ i){
		for(int j = 1 ; j <= c ; ++ j){
			if(s[i][j] == 'S')tx = i, ty = j;
			if(s[i][j] == 'E')sx = i, sy = j;
		}
	}
	bfs();
	int ans = 0;
	for(int i = 1 ; i <= r ; ++ i){
		for(int j = 1 ; j <= c ; ++ j){
			if(s[i][j] >= '0' && s[i][j] <= '9' && step[i][j] <= step[tx][ty])ans += s[i][j] - '0';
		}
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d", &r, &c);
	for(int i = 1 ; i <= r ; ++ i)scanf("%s", s[i]+1);
	solve();
	return 0;
}

