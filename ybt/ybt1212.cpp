#include <bits/stdc++.h>
using namespace std;

int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
char s[50][50];
int vis[1000];
int n,m,ans;

void dfs(int x,int y,int step){
    ans = max(ans,step);
    for(int i = 0 ; i < 4 ; ++ i){
        int dx = x + xx[i];
        int dy = y + yy[i];
        if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
        if(vis[s[dx][dy]])continue;
        vis[s[dx][dy]] = 1;
        dfs(dx,dy,step+1);
        vis[s[dx][dy]] = 0;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
    vis[s[1][1]] = 1;
    dfs(1,1,1);
    printf("%d\n",ans);
    return 0;
}
