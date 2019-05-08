#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y;
};
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};

int n,m;
char s[105][105];
int vis[105][105];
queue<node>q;

void BFS(int x,int y){
    q.push(node{x,y});
    vis[x][y] = 1;
    while(!q.empty()){
        node u = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; ++ i){
            int dx = u.x + xx[i];
            int dy = u.y + yy[i];
            if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
            if(vis[dx][dy] || s[dx][dy] == '0')continue;
            q.push(node{dx,dy});
            vis[dx][dy] = 1;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            if(!vis[i][j] && s[i][j] != '0')BFS(i,j), ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
