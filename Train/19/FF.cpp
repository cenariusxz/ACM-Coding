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
const int MAXN = 1000010;

map<pii ,int> mp;
int n,m,tot;
vector<pii > G[MAXN];
vector<int> Tm[MAXN];
queue<int> Q;
int vis[MAXN];
int pre[MAXN][2];

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		tot = 0;
		mp.clear();
		for(int i = 1; i <= 200000; ++i) G[i].clear();
		for(int i = 1; i <= 200000; ++i) Tm[i].clear();
		for(int i = 1; i <= m; ++i){
			int d1,d2,t1,t2;
			scanf("%d%d%d%d",&d1,&d2,&t1,&t2);
			if(mp[MP(d1,t1)] == 0) mp[MP(d1,t1)] = ++tot;
			if(mp[MP(d2,t2)] == 0) mp[MP(d2,t2)] = ++tot;
			int id1 = mp[MP(d1,t1)],id2 = mp[MP(d2,t2)];
			Tm[d1].PB(t1);
			Tm[d2].PB(t2);
			G[id1].PB(MP(id2,i));
		}
		int d1,d2,t1,t2;
		scanf("%d%d%d%d",&d1,&d2,&t1,&t2);
		if(mp[MP(d1,t1)] == 0) mp[MP(d1,t1)] = ++tot;
		if(mp[MP(d2,t2)] == 0) mp[MP(d2,t2)] = ++tot;
		int st = mp[MP(d1,t1)];
		int ed = mp[MP(d2,t2)];
		Tm[d1].PB(t1);
		Tm[d2].PB(t2);
		for(int i = 1; i <= n; ++i){
			if(Tm[i].size() == 0) continue;
			sort(Tm[i].begin(),Tm[i].end());
			for(int j = 0; j < Tm[i].size() - 1; ++j){
				int id1 = mp[MP(i,Tm[i][j])];
				int id2 = mp[MP(i,Tm[i][j + 1])];
				G[id1].PB(MP(id2,0));
			}
		}
		while(!Q.empty()) Q.pop();
		memset(vis,0,sizeof(vis));
		memset(pre,0,sizeof(pre));
		Q.push(st);
		vis[st] = 1;
		while(!Q.empty()){
			int x = Q.front(); Q.pop();
			for(int i = 0; i < G[x].size(); ++i){
				pii e = G[x][i];
				if(vis[e.first]) continue;
				vis[e.first] = 1;
				pre[e.first][0] = x;
				pre[e.first][1] = e.second;
				Q.push(e.first);
			}
		}
		if(vis[ed] == 0){
			printf("Impossible\n");
			continue;
		}
		vector<int> ans;
		int pos = ed;
		while(pos != st){
			if(pre[pos][1]) ans.PB(pre[pos][1]);
			pos = pre[pos][0];
		}
		printf("%d\n",(int)ans.size());
		for(int i = ans.size() - 1; i >= 0; --i){
			printf("%d",ans[i]);
			if(i) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
