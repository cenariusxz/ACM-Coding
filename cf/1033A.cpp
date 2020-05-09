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

struct node{
	int x, y;
};
int n, ax, ay, bx, by, cx, cy;
int vis[maxn][maxn];
int xx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int yy[8] = {1, 0, -1, 1, -1, 1, 0, -1};


void solve(){
	queue<node>q;
	q.push(node{bx, by});
	vis[bx][by] = 1;
	while(!q.empty()){
		node u = q.front(); q.pop();
		if(u.x == cx && u.y == cy){
			printf("YES\n");
			return;
		}
		for(int i = 0 ; i < 8 ; ++ i){
			int dx = u.x + xx[i], dy = u.y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > n || vis[dx][dy])continue;
			if(dx == ax || dy == ay || abs(dx - ax) == abs(dy - ay))continue;
			q.push(node{dx, dy});
			vis[dx][dy] = 1;
		}
	}
	printf("NO\n");
}

int main(){
	scanf("%d%d%d%d%d%d%d", &n, &ax, &ay, &bx, &by, &cx, &cy);
	solve();
	return 0;
}

