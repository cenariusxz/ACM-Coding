#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int INF=0x3f3f3f3f;
const int maxn=2e3+5;
const int maxm=2e5+5;

struct pii{
    int dis;
    int s;
    bool operator < (const pii x)const{
        return dis > x.dis;
    }
    pii(int _dis,int _s):dis(_dis),s(_s){};
};

struct edge{
	int to, val;
	edge(int _to, int _v):to(_to), val(_v){}
};

vector<edge> V[maxn];
int dis[maxn], n, m, k;

void dij(){
    priority_queue<pii> q;
    q.push( pii(0, 1) );
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    while(!q.empty()){
        pii u = q.top();
        q.pop();
        if(u.dis > dis[u.s])continue;
        for(int i = 0 ; i < V[u.s].size() ; ++ i){
        	int j = V[u.s][i].to, val = V[u.s][i].val;
            if(dis[j] > u.dis + val){
                dis[j] = u.dis + val;
                q.push(pii(dis[j], j));
            }
        }
    }
    if(dis[n] == INF)dis[n] = -1;
    printf("%d\n", dis[n]);
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
	dij();
	return 0;
}
