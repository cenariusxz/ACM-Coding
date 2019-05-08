#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 10010;
const int MAXM = 100010;

int n,m;

struct edge{
    int v,next,cost,cp;
};

struct MCMF{
    edge e[MAXM];
    int sou,sin;
    int first[MAXN],ecnt;
    int dis[MAXN];
    int prev[MAXN],pree[MAXN],inq[MAXN];
    void init(int a,int b){
        sou = a;
        sin = b;
        memset(first,-1,sizeof(first));
        ecnt = 0;
    }
    void add_edge(int u,int v,int cap,int fee){
        e[ecnt].next = first[u];
        e[ecnt].v = v;
        e[ecnt].cp = cap;
        e[ecnt].cost = fee;
        first[u] = ecnt++;

        e[ecnt].next = first[v];
        e[ecnt].v = u;
        e[ecnt].cp = 0;
        e[ecnt].cost = -fee;
        first[v] = ecnt++;
    }
    bool Spfa(){
        fill(dis,dis + MAXN,INF);
        dis[sou] = 0;
		memset(prev,-1,sizeof(prev));
		memset(inq,0,sizeof(inq));
        queue<int> Q;
        Q.push(sou);
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            inq[x] = 0;
            for(int i = first[x]; ~i; i = e[i].next){
                if(e[i].cp <= 0) continue;
                int v = e[i].v;
                if(dis[x] + e[i].cost < dis[v]){
                    dis[v] = dis[x] + e[i].cost;
                    prev[v] = x;
                    pree[v] = i;
                    if(inq[v] == 0){
                        inq[v] = 1;
                        Q.push(v);
                    }
                }
            }
        }
        return prev[sin] != -1;
    }
    int Solve(){
        //int sumf = 0;
        int min_cost = 0;
        while(Spfa()){
            int minf = INF;
            for(int i = sin; i != sou; i = prev[i]){
                int id = pree[i];
                minf = min(minf,e[id].cp);
            }
            for(int i = sin; i != sou; i = prev[i]){
                int id = pree[i];
                e[id].cp -= minf;
                e[id ^ 1].cp += minf;
            }
            //sumf += minf;
            min_cost += dis[sin] * minf;
        }
        //printf("flow : %d\n",sumf);
        return min_cost;
    }
}MC; 

int st,ed;

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		st = 0;
		ed = 2 * n + 1;
		MC.init(st,ed);
		MC.add_edge(st,1,2,0);
		MC.add_edge(1,n + 1,2,0);
		MC.add_edge(n,n + n,2,0);
		for(int i = 2; i < n; ++i){
			MC.add_edge(i,n + i,1,0);
		}
		for(int i = 1; i <= m; ++i){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			MC.add_edge(n + a,b,1,c);
		}
		MC.add_edge(n + n,ed,2,0);
		printf("%d\n",MC.Solve());
	}	
	return 0;
}
