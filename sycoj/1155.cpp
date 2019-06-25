#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

struct node{
    int x,y;	
};
node ans[105][105];

int n = 10;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
int M[105][105];

void bfs(int x,int y){
    queue<node>q;
    M[x][y] = 1;
    q.push(node{x,y});
    while(!q.empty()){
        node u = q.front();q.pop();
        for(int i = 0 ; i < 4 ; ++ i){
            int dx = u.x + xx[i];
            int dy = u.y + yy[i];
            if(dx < 1 || dx > n || dy < 1 || dy > n)continue;
            if(M[dx][dy])continue;
            M[dx][dy] = 1;
            q.push(node{dx,dy});	
        }
    }
}

int main(){
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= n ; ++ j){
            scanf("%d",&M[i][j]);
        }
    }
    for(int i = 1 ; i <= n ; ++ i){
        if(M[1][i] == 0)bfs(1,i);
        if(M[n][i] == 0)bfs(n,i);
        if(M[i][1] == 0)bfs(i,1);
        if(M[i][n] == 0)bfs(i,n);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= n ; ++ j){
            if(M[i][j] == 0)ans ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
