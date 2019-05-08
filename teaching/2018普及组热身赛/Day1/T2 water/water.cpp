#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;

struct node{
    int x,y,t;
    node(int _x, int _y, int _t):x(_x), y(_y), t(_t){}
};
int x[maxn],y[maxn];
int vis[maxn][maxn];
int ans[maxn],ti = 0;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
queue<node>q;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T2-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T2-") + ID[T] + "-l.out").c_str() ,"w",stdout);
//    freopen("T2-10.in","r",stdin);
//    freopen("T2-10.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    memset(ans,0,sizeof(ans));
    memset(vis,0,sizeof(vis));
    for(int i = 1 ; i <= k ; ++ i)scanf("%d%d",&x[i],&y[i]);
    for(int i = 1 ; i <= k ; ++ i)q.push(node(x[i],y[i],1));
    for(int i = 1 ; i <= k ; ++ i)vis[x[i]][y[i]] = 1;
    while(!q.empty()){
        node u = q.front(); q.pop();
        ti = u.t;
        ans[u.t]++;
        for(int i = 0 ; i < 4 ; ++ i){
            int dx = u.x + xx[i];
            int dy = u.y + yy[i];
            if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
            if(vis[dx][dy])continue;
            q.push(node(dx,dy,u.t+1));
            vis[dx][dy] = 1;
        }
    }
    for(int i = 2 ; i <= ti ; ++ i)ans[i] += ans[i-1];
    printf("%d\n",ti);
    for(int i = 1 ; i <= ti ; ++ i)printf("%d ",ans[i]);
    printf("\n");
    }
    return 0;
}
