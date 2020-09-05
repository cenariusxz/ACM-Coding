#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn=1e4+5;

int n, a[105][105], id[105][105], dis[maxn], x[maxn], y[maxn], vis[maxn];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};

void spfa(){
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    vis[ id[1][1] ] = 1;
    dis[ id[1][1] ] = 0;
    q.push(id[1][1]);
    while(!q.empty()){
        int u = q.front(); q.pop();
        int ux = x[u], uy = y[u];
        vis[u] = 0;
		for(int i = 0 ; i < 4 ; ++ i){
        	int tx = ux + xx[i], ty = uy + yy[i];
        	if(tx < 1 || tx > n || ty < 1 || ty > n)continue;
        	int j = id[tx][ty], val = abs(a[ux][uy] - a[tx][ty]);
            if(dis[j] > dis[u] + val){
                dis[j] = dis[u] + val;
                if(!vis[j]){
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
    }
    printf("%d\n", dis[ id[n][n] ]);
}

int main(){
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			scanf("%d", &a[i][j]);
			id[i][j] = ++ cnt;
			x[cnt] = i;
			y[cnt] = j;
		}
	}
	spfa();
	return 0;
}
