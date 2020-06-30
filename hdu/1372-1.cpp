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
char s[5], t[5];
int sx, sy, tx, ty, vis[10][10];
int xx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int yy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int bfs(){
    queue<node>q;
    q.push(node{sx, sy, 0});
    vis[sx][sy] = 1;
    if(sx == tx && sy == ty)return 0;
    while(!q.empty()){
        node u = q.front(); q.pop();
        for(int i = 0 ; i < 8 ; ++ i){
            int dx = u.x + xx[i], dy = u.y + yy[i];
            if(dx < 1 || dx > 8 || dy < 1 || dy > 8 || vis[dx][dy])continue;
            q.push(node{dx, dy, u.t + 1});
            vis[dx][dy] = 1;
            if(dx == tx && dy == ty)return u.t + 1;
        }
    }
}

void solve(){
    memset(vis,0,sizeof(vis));
    sx = s[0] - 'a' + 1, sy = s[1] - '0';
    tx = t[0] - 'a' + 1, ty = t[1] - '0';
    printf("To get from %s to %s takes %d knight moves.\n", s, t, bfs());
}

int main(){
    while(scanf("%s%s", s, t) != EOF)solve();
    return 0;
}
