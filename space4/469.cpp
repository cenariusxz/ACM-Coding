#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using  namespace std;
const int maxn = 1005;
const int maxm = 40000;

struct Edge{
  int v, w;
  Edge(){}
  Edge(int v, int w):v(v), w(w){}
};
vector<Edge> G[maxn];
int dis[maxn], cnt[maxn], inQ[maxn], n, m1, m2;

queue<int> Q;
bool SPFA(int s) {
  memset(dis, 0x3f, sizeof(dis));
  memset(cnt, 0, sizeof(cnt));
  memset(inQ, 0, sizeof(inQ));
  dis[s] = 0;
  Q.push(s);
  inQ[s] = 1;
  cnt[s] ++;

  while(!Q.empty()) {
    int u = Q.front(); Q.pop();
    inQ[u] = 0;
    for(int i = 0; i < G[u].size() ; ++ i) {
      int v = G[u][i].v, w = G[u][i].w;
      if(dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if(inQ[v] == 0) {
          Q.push(v);
          inQ[v] = 1;
          cnt[v] ++;
          if(cnt[v] > n) return true;
        }
      }
    }
  }
  return false;

}


int main() {
    cin >> n >> m1 >> m2;
    for(int i = 0, u, v, x; i < m1; i++) {
      cin >> u >> v >> x;
      G[min(u, v)].push_back(Edge(max(u, v), x));
    }
    for(int i = 0, u, v, x; i < m2; i++) {
      cin >> u >> v >> x;
      G[max(u, v)].push_back(Edge(min(u, v), -x));
    }
    for(int i = 2; i <= n; i++) G[i].push_back(Edge(i-1, 0));

    if(SPFA(1)) {
      cout << -1 << endl;
    } else if(dis[n] == 0x3f3f3f3f) {
      cout << -2 << endl;
    } else {
      cout << dis[n] << endl;
    }
  return 0;
}
