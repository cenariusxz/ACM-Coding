#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

struct node{
    int x,y,c,t;
};
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};

int s[105][105],n,m;
int vis[105][105][3];

int BFS(){
    memset(vis,0x3f,sizeof(vis));
    queue<node>q;
    vis[1][1][s[1][1]] = 0;
    q.push(node{1,1,s[1][1],0});
    while(!q.empty()){
        node u = q.front();q.pop();
        for(int i = 0 ; i < 4 ; ++ i){
            int dx = u.x + xx[i];
            int dy = u.y + yy[i];
            int cost,col;
            if(dx < 1 || dx > m || dy < 1 || dy > m)continue;
            if( !s[u.x][u.y] && !s[dx][dy] )continue;
            if( !s[dx][dy] ){
                col = u.c;
                cost = u.t + 2;
            }
            else if( u.c == s[dx][dy] ){
                col = s[dx][dy];
                cost = u.t;
            }
            else{
                col = s[dx][dy];
                cost = u.t + 1;
            }
            if(cost < vis[dx][dy][col]){
                vis[dx][dy][col] = cost;
                q.push(node{dx,dy,col,cost});
            }
        }
    }
    return min(vis[m][m][1], vis[m][m][2]);
}

int main(){
    scanf("%d%d",&m,&n);
    while(n--){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        s[x][y] = c+1;
    }
    int ans = BFS();
    if(ans == INF)ans = -1;
    printf("%d\n",ans);
    return 0;
}
