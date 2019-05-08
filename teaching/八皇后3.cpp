#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int que[10],vis[10];
int chess[10][10];
int sum;
int xx[4]={1,1,-1,-1};
int yy[4]={1,-1,1,-1};

void check(){
    memset(chess,0,sizeof(chess));
    for(int i = 1 ; i <= 8 ; ++ i){
        chess[i][que[i]] = 1;
    }
    bool flag = false;
    for(int i = 1 ; i <= 8 ; ++ i){
        int x = i, y = que[i];
        for(int d = 0 ; d < 4 ; ++ d){
            int dx = x, dy = y;
            while(1){
                dx += xx[d];
                dy += yy[d];
                if(dx < 1 || dx > 8 || dy < 1 || dy > 8)break;
                if(chess[dx][dy])flag = true;
            }
        }
    }
    if(!flag){
        ++sum;
        for(int i = 1 ; i <= 8 ; ++ i){
            printf("%d ",que[i]);
        }
        printf("\n");
    }
}

void dfs(int t){
    if(t == 8){
        check();
        return;
    }
    for(int i = 1 ; i <= 8 ; ++ i){
        if(vis[i])continue;
        vis[i] = 1;
        que[t+1] = i;
        dfs(t+1);
        vis[i] = 0;
    }
}

int main(){
    sum = 0;
    dfs(0);
    printf("%d\n",sum);
	return 0;
}
