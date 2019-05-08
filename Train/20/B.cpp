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
const int MAXN = 110;
const int MAXM = 110 * 110 * 2;

int T,N,M;
int A[MAXN],B[MAXN],S[MAXN],ned[MAXN],sum;
int C[MAXN][MAXN];
int D[MAXN][MAXN];

struct edge{
	int v,next,c;
};

struct Max_flow{
	int st,ed,lev[MAXN],first[MAXN],now[MAXN],ecnt;
	edge e[MAXM];
	void init(int a,int b){
		st = a,ed = b;
		memset(first,-1,sizeof(first));
		ecnt = 0;
	}
	void add_edge(int u,int v,int c){
		e[ecnt].next = first[u];
		e[ecnt].v = v;
		e[ecnt].c = c;
		first[u] = ecnt++;

		e[ecnt].next = first[v];
		e[ecnt].v = u;
		e[ecnt].c = 0;
		first[v] = ecnt++;
	}
	bool bfs(){
		queue<int> Q;
		while(!Q.empty()) Q.pop();
		Q.push(st);
		memset(lev,-1,sizeof(lev));
		lev[st] = 0;
		while(!Q.empty()){
			int x = Q.front(); Q.pop();
			for(int i = first[x]; ~i; i = e[i].next){
				int v = e[i].v;
				if(lev[v] < 0 && e[i].c > 0){
					lev[v] = lev[x] + 1;
					Q.push(v);
				}
			}
		}
		return lev[ed] != -1;
	}
	int dfs(int p,int minf){
		if(p == ed || minf == 0) return minf;
		for(int &i = now[p]; ~i; i = e[i].next){
			int v = e[i].v;
			if(lev[v] == lev[p] + 1 && e[i].c > 0){
				int d = dfs(v,min(e[i].c,minf));
				if(d > 0){
					e[i].c -= d;
					e[i ^ 1].c += d;
					return d;
				}
			}
		}
		return 0;
	}
	int dinic(){
		int max_flow = 0,pl;
		while(bfs()){
			memcpy(now,first,sizeof(first));
			while((pl = dfs(st,INF)) > 0){
				max_flow += pl;
			}
		}
		return max_flow;
	}
}MF;

bool Check(int v){
	int st0 = 2 * N + 1;
	int st1 = st + 1;
	int st2 = st1 + 1;
	int ed1 = 2 * N + 4;
	int ed0 = ed1 + 1;
	MF.init(st0,ed0);
	MF.add_edge(st0,st1,v);
	MF.add_edge(st1,st2,INF);
	MF.add_edge(ed1,ed0,INF);
	for(int i = 1; i <= N; ++i){
		int i1 = i * 2 - 1;
		int i2 = i * 2;
		MF.add_edge(st1,i2,ned[i]);
		MF.add_edge(i1,ed0,ned[i]);
		MF.add_edge(st2,i1,INF);
		MF.add_edge(i2,ed1,INF);
	}
	
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d",&N,&M);
		for(int i = 1; i <= N; ++i){
			scanf("%d%d%d",&A[i],&B[i],&S[i]);
			ned[i] = S[i] / M;
			if(ned[i] * M < S[i]) ned[i]++;
		}
		sum = 0;
		for(int i = 1; i <= N; ++i){
			sum += ned[i];
		}
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= N; ++j){
				scanf("%d",&C[i][j]);
			}
		}
		memset(D,0,sizeof(D));
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= N; ++j){
				if(i == j || A[j] < B[i]) continue;
				if(A[j] - B[i] >= C[i][j]){
					D[i][j] = 1;
				}
			}
		}
		int l = 1,r = 1000000;
		while(l < r){
			int mid = getmid(l,r);
			if(Check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("Case %d: %d\n",tt,l);
	}
	return 0;
}
