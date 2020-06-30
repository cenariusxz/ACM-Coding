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
    int x, y, z, t;
};
int s[55][55][55], vis[55][55][55];
int a, b, c, t;
int xx[6] = {1, -1, 0, 0, 0, 0};
int yy[6] = {0, 0, 1, -1, 0, 0};
int zz[6] = {0, 0, 0, 0, 1, -1};

int bfs(){
    queue<node>q;
    q.push(node{1, 1, 1, 0});
    vis[1][1][1] = 1;
    if(a == 1 && b == 1 && c == 1)return 1;
    while(!q.empty()){
        node u = q.front(); q.pop();
        if(u.t == t)continue;
        for(int i = 0 ; i < 6 ; ++ i){
            int dx = u.x + xx[i], dy = u.y + yy[i], dz = u.z + zz[i];
            if(dx < 1 || dx > a || dy < 1 || dy > b || dz < 1 || dz > c || s[dx][dy][dz] == 1 || vis[dx][dy][dz])continue;
            q.push(node{dx, dy, dz, u.t + 1});
            vis[dx][dy][dz] = 1;
            if(dx == a && dy == b && dz == c)return u.t + 1;
        }
    }
    return -1;
}

void solve(){
    memset(vis, 0, sizeof(vis));
    scanf("%d%d%d%d", &a, &b, &c, &t);
    for(int i = 1 ; i <= a ; ++ i){
        for(int j = 1 ; j <= b ; ++ j){
            for(int k = 1 ; k <= c ; ++ k){
                scanf("%d", &s[i][j][k]);
            }
        }
    }
    printf("%d\n", bfs());
}

int main(){
    int k;
    scanf("%d", &k);
    while(k--)solve();
    return 0;
}
