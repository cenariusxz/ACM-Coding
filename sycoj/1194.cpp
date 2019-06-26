#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y;
    node(int _x,int _y):x(_x),y(_y){}
};

int n,m;
int vis[405][405];
int xx[8] = {-2,-2,-1,-1,1,1,2,2};
int yy[8] = {1,-1,2,-2,2,-2,1,-1};

int main(){
    int x1,y1;
    scanf("%d%d%d%d",&n,&m,&x1,&y1);
    queue<node>q;
    vis[x1][y1] = 1;
    q.push(node(x1,y1));
    while(!q.empty()){
        node u = q.front();q.pop();
        for(int i = 0 ; i < 8 ; ++ i){
            int dx = u.x + xx[i];
            int dy = u.y + yy[i];
            if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
            if(vis[dx][dy])continue;
            vis[dx][dy] = vis[u.x][u.y] + 1;
            q.push(node(dx,dy));
        }
    }
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            printf("%-5d",vis[i][j]-1);
        }
        printf("\n");
    }
    return 0;
}
