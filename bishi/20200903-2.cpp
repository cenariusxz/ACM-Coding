#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MP make_pair
const int INF = 0x3f3f3f3f;
const int maxn=1e4+5;

int n, a[105][105], id[105][105], dis[maxn], x[maxn], y[maxn];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};

struct cmp{
    bool operator()(pii a, pii b){
        return a.first > b.first;
    }
};

void dij(){
    priority_queue<pii, vector<pii>, cmp> q;
    q.push(make_pair(0, id[1][1]));
    memset(dis, 0x3f, sizeof(dis));
    dis[ id[1][1] ] = 0;
    while(!q.empty()){
        pii u = q.top(); q.pop();
        if(u.first > dis[u.second])continue;
        int s = u.second, sx = x[u.second], sy = y[u.second];
        for(int i = 0 ; i < 4 ; ++ i){
        	int tx = sx + xx[i], ty = sy + yy[i];
        	if(tx < 1 || tx > n || ty < 1 || ty > n)continue;
            int j = id[tx][ty], val = abs(a[sx][sy] - a[tx][ty]);
            if(dis[j] > u.first + val){
                dis[j] = u.first + val;
                q.push(make_pair(dis[j], j));
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
	dij();
	return 0;
}
