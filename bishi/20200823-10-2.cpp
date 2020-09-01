#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int INF=0x3f3f3f3f;
const int maxn=2e3+5;

struct edge{
	int to, val;
	edge(int _to, int _v):to(_to), val(_v){}
};

vector<edge> V[maxn];
int dis[maxn],vis[maxn], n, m, k;

void spfa(){
    memset(dis,0x3f,sizeof(dis));
    queue<int>q;
    vis[1]=1; dis[1]=0;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u]=0;
        for(int i = 0 ; i < V[u].size() ; ++ i){
        	int j = V[u][i].to, val = V[u][i].val;
            if(dis[j] > dis[u] + val){
                dis[j] = dis[u] + val;
                if(!vis[j]){
                    q.push(j);
                    vis[j]=1;
                }
            }
        }
    }
    if(dis[n] == INF)dis[n] = -1;
    printf("%d\n",dis[n]);
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	while(m --){
		int a, b, v;
		scanf("%d%d%d", &a, &b, &v);
		V[a].PB(edge(b, v));
		V[b].PB(edge(a, v));
	}
	while(k --){
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(edge(b, 0));
	}
	spfa();
	return 0;
}
