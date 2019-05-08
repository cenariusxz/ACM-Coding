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
const int MAXN = 210;

int T,N,M;
double V[MAXN][3];
double G[MAXN][MAXN];
double dis[MAXN];
int inq[MAXN],pre[MAXN];

double Dis(int a,int b){
	return sqrt(1.0 * (V[a][1] - V[b][1]) * (V[a][1] - V[b][1]) +
			1.0 * (V[a][2] - V[b][2]) * (V[a][2] - V[b][2]));
}

void Update(double &x,double y){
	if(x == -1) x = y;
	else if(y < x) x = y;
}

void Spfa(int st,int ed){
	memset(inq,0,sizeof(inq));
	memset(pre,0,sizeof(pre));
	for(int i = 0; i < N; ++i) dis[i] = 1LL << 60;
	queue<int> Q;
	dis[st] = 0;
	Q.push(st);
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		if(x == ed) continue;
		for(int i = 0; i < N; ++i) if(i != x){
			if(G[x][i] == -1) continue;
			if(dis[i] > dis[x] + G[x][i]){
				dis[i] = dis[x] + G[x][i];
				pre[i] = x;
				if(inq[i] == 0){
					inq[i] = 1;
					Q.push(i);
				}
			}
		}
	}
}

double DD(int a,int b){
	return sqrt(25 * (V[a][0] - V[b][0]) * (V[a][0] -
				V[b][0]) + (V[a][1] - V[b][1]) * (V[a][1] - V[b][1])
			+ (V[a][2] - V[b][2]) * (V[a][2] - V[b][2]));
}

int main(){
	int f = 0;
	while(scanf("%d%d",&N,&M) != EOF){
		if(f) puts("");
		f = 1;
		for(int i = 0; i < N; ++i){
			G[i][i] = 0;
			for(int j = 0; j < N; ++j){
				if(i == j) continue;
				G[i][j] = -1;
			}
		}
		for(int i = 0; i < N; ++i){
			scanf("%lf%lf%lf",&V[i][0],&V[i][1],&V[i][2]);
		}
		for(int i = 1; i <= M; ++i){
			int a,b;
			char s[15];
			scanf("%d%d%s",&a,&b,s);
			if(s[0] == 'w'){
				Update(G[a][b],Dis(a,b));
				Update(G[b][a],Dis(a,b));
			}
			else if(s[0] == 's'){
				Update(G[a][b],DD(a,b));
				Update(G[b][a],DD(a,b));
			}
			else if(s[0] == 'l'){
				Update(G[a][b],1);
				Update(G[b][a],1);
			}
			else{
				// es
				Update(G[a][b],1);
				
				Update(G[b][a],3.0 * DD(a,b));
			}
		}
		int Q;
		scanf("%d",&Q);
		for(int i = 1; i <= Q; ++i){
			int a,b;
			scanf("%d%d",&a,&b);
			Spfa(a,b);
			int pos = b;
			vector<int> ans;
			while(1){
				ans.PB(pos);
				if(pos == a) break;
				pos = pre[pos];
			}
			for(int i = ans.size() - 1; i >= 0; --i){
				printf("%d",ans[i]);
				if(i == 0) puts("");
				else printf(" ");
			}
		}
	}
	return 0;
}
