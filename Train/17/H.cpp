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
const int MAXN = 1010;

int n,m;
int first[MAXN],ecnt;
int bg[MAXN << 1],dfn[MAXN],low[MAXN],tot;
int vis[MAXN << 1];
int E[MAXN << 1][2];

struct edge{
	int u,v,next;
}e[MAXN << 1];

void Dfs(int p,int pre){
	dfn[p] = low[p] = ++tot;
	for(int i = first[p]; ~i; i = e[i].next){
		if(vis[i]) continue;
		vis[i] = vis[i ^ 1] = 1;
		int v = e[i].v;
		if(v == pre) continue;
		if(!dfn[v]){
			Dfs(v,p);
			low[p] = min(low[p],low[v]);
			if(low[v] > dfn[p]) bg[i] = bg[i ^ 1] = 1;
		}
		else{
			low[p] = min(low[p],dfn[v]);
		}
	}
}

void Tarjan(){
	tot = 0;
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(bg,0,sizeof(bg));
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) Dfs(i,-1);
}

inline void add_edge(int u,int v){
	e[ecnt].next = first[u];
	e[ecnt].u = u;
	e[ecnt].v = v;
	first[u] = ecnt++;
}

void Init(){
	memset(first,-1,sizeof(first));
	ecnt = 0;
	memset(vis,0,sizeof(vis));
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		if(n == -1 && m == -1) break;
		Init();
		for(int i = 1; i <= m; ++i){
			int a,b;
			scanf("%d%d",&a,&b);
			a++; b++;
			E[i][0] = a;
			E[i][1] = b;
			add_edge(a,b);
			add_edge(b,a);
		}
		Tarjan();
		bool flag = 0;
		for(int i = 0; i < ecnt; ++i){
			if(bg[i]){
				flag = 1;
				break;
			}
		}
		if(flag){
			printf("NO\n");
			continue;
		}
		for(int i = 1; i <= m; ++i){
			// delete edge i
			Init();
			for(int j = 1; j <= m; ++j) if(i != j){
				add_edge(E[j][0],E[j][1]);
				add_edge(E[j][1],E[j][0]);
			}
			Tarjan();
			int bc = 0;
			for(int k = 0; k < ecnt; ++k){
				if(bg[k]) bc++;
			}
			if(bc >= 4){
				printf("Delete : %d %d\n",E[i][0],E[i][1]);
				printf("bc : %d\n",bc);
				flag = 1;
				//printf("Delete %d %d\n",E[i][0],E[i][1]);
				//for(int o = 0; o < ecnt; ++o) if(bg[o]){
				//	printf("D %d %d\n",e[o].u,e[o].v);
				//}
				break;
			}
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
