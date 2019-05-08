#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stack>
using namespace std;
const int MAXN = 4000;

int n,m,tot,scnt;
int first[MAXN],ecnt;
int low[MAXN],dfn[MAXN],sc[MAXN];
stack<int> s;

struct edge{
	int v,next;
}e[MAXN << 1];

inline void add_edge(int u,int v){
	e[ecnt].next = first[u];
	e[ecnt].v = v;
	first[u] = ecnt++;
}

inline void Init(){
	memset(first,-1,sizeof(first));
	ecnt = tot = scnt = 0;
}

void Dfs1(int p){
	dfn[p] = low[p] = ++tot;
	s.push(p);
	for(int i = first[p]; ~i; i = e[i].next){
		int v = e[i].v;
		if(!dfn[v]){
			Dfs1(v);
			low[p] = min(low[p],low[v]);
		}
		else if(!sc[v]){
			low[p] = min(low[p],dfn[v]);
		}
	}
	if(low[p] == dfn[p]){
		++scnt;
		while(1){
			int x = s.top();
			s.pop();
			sc[x] = scnt;
			if(x == p) break;
		}
	}
}

void Tarjan(){
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(sc,0,sizeof(sc));
	while(!s.empty()) s.pop();
	int top = 2 * n;
	for(int i = 1; i <= top; ++i)
		if(!dfn[i]) Dfs1(i);
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		Init();
		add_edge(n + 1,1);
		for(int i = 1; i <= m; ++i){
			int a,b;
			scanf("%d%d",&a,&b);
			int id1 = (a > 0) ? a : n - a;
			int ID1 = (a > 0) ? n + a : -a;
			int id2 = (b > 0) ? b : n - b;
			int ID2 = (b > 0) ? n + b : -b;
			add_edge(ID1,id2);
			add_edge(ID2,id1);
		}
		Tarjan();
		//for(int i = 1; i <= 2 * n; ++i){
		//	printf("sc[%d] : %d\n",i,sc[i]);
		//}
		int flag = 1;
		for(int i = 1; i <= n; ++i){
			if(sc[i] == sc[n + i]){
				flag = 0;
				break;
			}
		}
		if(flag) printf("yes\n");
		else printf("no\n");
	}	
	return 0;
}
