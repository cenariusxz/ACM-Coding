#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y;
};
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};

char s[105][105];
int a[105][105],n,m;
int used[105][105];

int main(){
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m == 0 && n == 0)break;
        for(int i = 1 ; i <= n ;++ i)scanf("%s",s[i]+1);

        int stx,sty;
        for(int i = 1 ; i <= n ; ++ i){
            for(int j = 1 ; j <= m ; ++ j){
                if(s[i][j] == '@')stx = i,sty = j;
            }
        }
        int ans = 0;
        memset(used,0,sizeof(used));

        queue<node>q;
        used[stx][sty]=1;
        q.push(node{stx,sty,0});

        while(!q.empty()){
            node u = q.front();
            q.pop();
            if(s[u.x][u.y] == 'T'){
                printf("%d\n",u.k);
                break;
            }
            for(int i = 0 ; i < 4 ; ++ i){
                int dx = u.x + xx[i];
                int dy = u.y + yy[i];
                if(dx < 1 || dx > n || dy < 1 || dy >m)continue;
                if(used[dx][dy])continue;
                if(s[dx][dy] == '#')continue;
                used[dx][dy] = 1;
                q.push(node{dx,dy,u.k+1});
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
