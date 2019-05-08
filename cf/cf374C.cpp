#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e6 + 5;

int n,m;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
char s[1005][1005];
int id[1005][1005];
int dis[maxn];
int head[maxn],point[maxn<<2],nxt[maxn<<2],size;
int vis[maxn];
bool flag = false;

void init(){
    size = 0;
    memset(head,-1,sizeof(head));
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    flag = false;
}

void add(int a, int b){
    point[size] = b;
    nxt[size] = head[a];
    head[a] = size++;
}

void dfs(int s){
    if(dis[s])return;
    vis[s] = 1;
    dis[s] = 1;
    for(int i = head[s] ; ~ i ; i = nxt[i]){
        int j = point[i];
        if(vis[j]){flag = true;vis[s] = 0;return;}
        dfs(j);
        if(flag){vis[s] = 0;return;}
        dis[s] = max(dis[s],dis[j]+1);
    }
    vis[s] = 0;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
    int cnt = 0;
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            id[i][j] = ++ cnt;
        }
    }
    init();
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            for(int k = 0 ; k < 4 ; ++ k){
                int dx = i + xx[k];
                int dy = j + yy[k];
                if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
                if(s[i][j] == 'D' && s[dx][dy] == 'I')add(id[i][j],id[dx][dy]);
                if(s[i][j] == 'I' && s[dx][dy] == 'M')add(id[i][j],id[dx][dy]);
                if(s[i][j] == 'M' && s[dx][dy] == 'A')add(id[i][j],id[dx][dy]);
                if(s[i][j] == 'A' && s[dx][dy] == 'D')add(id[i][j],id[dx][dy]);
            }
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            if(s[i][j] != 'D')continue;
            dfs(id[i][j]);
            if(flag == true){
                printf("Poor Inna!\n");
                return 0;
            }
            if(dis[id[i][j]] > ans)ans = dis[id[i][j]];
        }
    }
    ans /= 4;
    if(ans)printf("%d\n",ans);
    else printf("Poor Dima!\n");
	return 0;
}
