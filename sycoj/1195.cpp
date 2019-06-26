#include <bits/stdc++.h>
using namespace std;

int xx[8] = {-1,-1,-1,0,0,1,1,1};
int yy[8] = {-1,0,1,-1,1,-1,0,1};

int n,m,a[10][10],vis[10][10],ans,cnt = 0;
int x[105],y[105];
int T;

void dfs(int id,int sum){
    if(id == cnt){
        ans = max(ans,sum);
        return;
    }
    int nowx = x[id+1], nowy = y[id+1];
    dfs(id+1,sum);
    for(int i = 0 ; i < 8 ; ++ i){
        int dx = nowx + xx[i];
        int dy = nowy + yy[i];
        if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
        if(vis[dx][dy])return;
    }
    vis[nowx][nowy] = 1;
    dfs(id+1,sum+a[nowx][nowy]);
    vis[nowx][nowy] = 0;
}

int main(){
    scanf("%d",&T);
    while(T--){
        cnt = 0; ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1 ; i <= n ; ++ i){
            for(int j = 1 ; j <= m ; ++ j){
                scanf("%d",&a[i][j]);
                vis[i][j] = 0;
                ++cnt;
                x[cnt] = i; y[cnt] = j;
            }
        }
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
