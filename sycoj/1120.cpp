#include <bits/stdc++.h>
using namespace std;

int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
char s[50][50];
int vis[50][50],n,m,ans;

void dfs(int x,int y){
    vis[x][y] = 1;
    ans ++;
    for(int i = 0 ; i < 4 ; ++ i){
        int dx = x + xx[i];
        int dy = y + yy[i];
        if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
        if(vis[dx][dy] || s[dx][dy] == '#')continue;
        dfs(dx,dy);
    }
}

int main(){
    while(scanf("%d%d",&m,&n) && (n||m)){
        ans = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
        for(int i = 1 ; i <= n ; ++ i){
            for(int j = 1 ; j <= m ; ++ j){
                if(s[i][j] == '@')dfs(i,j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
