#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int maxm = 8e5 + 5;
const int INF = 0x3f3f3f3f;
 
int dis[105][105][3];
int n,m;
int col[105][105];
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};
 
struct node{
    int x,y,d,c;
    node(int _x,int _y,int _d,int _c):x(_x),y(_y),d(_d),c(_c){}
    node(){}
    bool operator < (const node x)const{
        return d > x.d;  
    }
};
 
void init(){
    memset(col,0,sizeof(col));
}
 
void dij(int x1,int y1,int x2,int y2){
    priority_queue<node>q;
    memset(dis,0x3f,sizeof(dis));
    dis[x1][y1][col[x1][y1]] = 0;
    q.push(node(x1,y1,0,col[x1][y1]));
    while(!q.empty()){
        node u = q.top();
        q.pop();
        if(u.x == x2 && u.y == y2){
            printf("%d\n",u.d);
            return; 
        }
        if(u.d > dis[u.x][u.y][u.c])continue;
        int x = u.x,y = u.y;
        for(int i = 0;i < 4; ++i){
            int dx = u.x + xx[i],dy = u.y+yy[i];
            if(dx < 1 || dx > m || dy < 1 || dy > m)continue;
            if(col[x][y] == 0 &&col[dx][dy] == 0)continue;
            int v = 0;
             
            if(col[dx][dy]==0){
                v = 2;
                int c = u.c;
                if(dis[dx][dy][c] > u.d + v){
                    dis[dx][dy][c] = u.d+v;
                    q.push(node(dx,dy,dis[dx][dy][c],c));
                }
                v = 3;
                c = 3-u.c;
                if(dis[dx][dy][c] > u.d + v){
                    dis[dx][dy][c] = u.d+v;
                    q.push(node(dx,dy,dis[dx][dy][c],c));
                }
                continue;
            }
            if(u.c == col[dx][dy])v = 0;
            if(u.c + col[dx][dy] == 3)v=1;
             
            if(dis[dx][dy][col[dx][dy]] > u.d + v){
                dis[dx][dy][col[dx][dy]] = u.d+v;
                q.push(node(dx,dy,dis[dx][dy][col[dx][dy]],col[dx][dy]));
            }
             
        }
    }
    printf("-1\n");
}
 
int main(){
    while(scanf("%d%d",&m,&n)!=EOF){
        init();
        for(int i = 1 ; i <= n ; ++ i){
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            if(c == 0)c =2;
            col[x][y] = c;
        }
        dij(1,1,m,m);
    }
    return 0;
}
