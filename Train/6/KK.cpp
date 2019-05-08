#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;

int dp[10010];
int T,N,M,L;
int C[110],V[110];
int pos[110];
int dis[110];
int inq[110];
int first[110],ecnt;

struct edge{
	int v,nxt;
}e[2 * 110 * 110];

void Spfa(){
	queue<int> Q;
	memset(inq,0,sizeof(inq));
	fill(dis + 1,dis + N + 1,INF);
	Q.push(1);
	inq[1] = 1;
	dis[1] = 0;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		for(int i = first[x]; ~i; i = e[i].nxt){
			int v = e[i].v;
			if(dis[v] > dis[x] + 1){
				dis[v] = dis[x] + 1;
				if(inq[v] == 0){
					inq[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

inline void add_edge(int u,int v){
	e[ecnt].nxt = first[u];
	e[ecnt].v = v;
	first[u] = ecnt++;
}

int main(){
	scanf("%d",&T);
	while(T--){
		memset(first,-1,sizeof(first));
		ecnt = 0;
		scanf("%d%d%d",&N,&M,&L);
		for(int i = 1; i <= N; ++i){
			scanf("%d",&pos[i]);
		}
		sort(pos + 1,pos + N + 1);
		int sum = 0;
		for(int i = 1; i <= M; ++i){
			scanf("%d%d",&C[i],&V[i]);
			sum += V[i];
		}
		memset(dp,0x3f,sizeof(dp));
		dp[0] = 0;
		for(int i = 1; i <= M; ++i){
			for(int j = sum; j >= V[i]; --j){
				dp[j] = min(dp[j],dp[j - V[i]] + C[i]);
			}
		}
		for(int j = 0; j <= sum; ++j){
			dp[j] = (dp[j] <= L);
			//if(dp[j]) printf("ac : %d\n",j);
		}
		for(int i = 1; i <= N; ++i){
			for(int j = i + 1; j <= N; ++j){
				int dis = abs(pos[i] - pos[j]);
				if(dp[dis] == 1){
					//printf("%d %d\n",i,j);
					add_edge(i,j);
					add_edge(j,i);
				}
			}
		}
		Spfa();
		if(dis[N] == INF) printf("-1\n");
		else printf("%d\n",dis[N]);
	}
	return 0;
}
