#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y,t,d;
    node(int _x,int _y,int _t,int _d):x(_x),y(_y),t(_t),d(_d){}
};
// N->0 E->1 S->2 W->3
int xx[4] = {-1,0,1,0};
int yy[4] = {0,1,0,-1};

int vis[55][55][4];
int M[55][55];
int n,m;
int sx,sy,tx,ty;
char s[10];

int solve(){
    int d;
    queue<node>q;
    if(s[0] == 'N')d=0;
    if(s[0] == 'E')d=1;
    if(s[0] == 'S')d=2;
    if(s[0] == 'W')d=3;
    q.push(node(sx,sy,0,d));
    vis[sx][sy][d] = 1;
    while(!q.empty()){
        node u = q.front();q.pop();
        if(u.x == tx && u.y == ty)return u.t;
        u.t++;
        node tmp = u;
        for(int i = 1 ; i <= 3 ; ++ i){
            tmp.x += xx[tmp.d];
            tmp.y += yy[tmp.d];
            if(tmp.x <= 1 || tmp.x >= n || tmp.y <= 1 || tmp.y >= m)continue;
            if(vis[tmp.x][tmp.y][tmp.d])continue;
            if(M[tmp.x][tmp.y])break;
            q.push(tmp);
            vis[tmp.x][tmp.y][tmp.d] = 1;
        }
        tmp = u;
        tmp.d = (tmp.d + 1)%4;
        if(!vis[tmp.x][tmp.y][tmp.d]){
            q.push(tmp);
            vis[tmp.x][tmp.y][tmp.d] = 1;
        }
        tmp = u;
        tmp.d = (tmp.d - 1 + 4)%4;
        if(!vis[tmp.x][tmp.y][tmp.d]){
            q.push(tmp);
            vis[tmp.x][tmp.y][tmp.d] = 1;
        }
    }
    return -1;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            int a;
            scanf("%d",&a);
            if(a){
                M[i][j] = 1; M[i][j+1] = 1;
                M[i+1][j] = 1; M[i+1][j+1] = 1;
            }
        }
    }
    n++;m++;
    scanf("%d%d%d%d%s",&sx,&sy,&tx,&ty,s);
    sx++;sy++;tx++;ty++;
    printf("%d\n",solve());
    return 0;
}
