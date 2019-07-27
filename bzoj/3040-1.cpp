#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 1e7 + 5;
const int tt = 1e8;
int n, m, dis[maxn];
int t, rxa, rxc, rya, ryc, rp;
struct edge{
    int to, w, next;
} ed[maxm];
int head[maxn], tot;
bool vis[maxn];
inline void add( int u, int v, int w ){
    ed[++tot].to = v;
    ed[tot].w = w;
    ed[tot].next = head[u];
    head[u] = tot;
}
inline void dij(int beg){
    priority_queue< pair<int, int> > q;
    dis[beg] = 0;
    q.push(make_pair(0, beg));
    while( !q.empty() ){
        int u = q.top().second;
        q.pop();
        if( vis[u] ) continue;
        vis[u] = 1;
        for( int i=head[u]; i!=0; i=ed[i].next ){
            int v = ed[i].to;
            if(vis[v]) continue;
            if( dis[v]>dis[u]+ed[i].w ){
                dis[v] = dis[u]+ed[i].w;
                q.push( make_pair(-dis[v], v) );
            }
        }
    }
}
   
int main(){
    memset( vis, 0, sizeof(vis) );
    memset( dis, 0x3f, sizeof(dis) );
    tot = 1;
    scanf("%d%d", &n, &m);
    scanf("%d %d %d %d %d %d", &t, &rxa, &rxc, &rya, &ryc, &rp);
int x, y, a, b;
x = y = 0;
    for( int i=0; i<t; i++ ){
          
        x = (x*rxa+rxc)%rp;
        y = (y*rya+ryc)%rp;
        a = min(x%n+1, y%n+1);
        b = max(y%n+1, y%n+1);
        if(a < 0)return 0;
        int w = tt-100*a;
        add( a, b, w );
    }
    for( int i=t; i<m; i++ ){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add( u, v, w );
    }
    dij(1);
    printf("%d\n", dis[n]);
   
    return 0;
}
