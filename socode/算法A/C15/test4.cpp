#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int id[maxn],n,m,vis[maxn];
vector<int>V[maxn];

bool topo(){
	queue<int>q;
	for(int i = 1 ; i <= n ; ++ i){
		if(id[i] == 0)q.push(i);	
	}
	int cnt = 0;
	while(!q.empty()){
		int u = q.front();q.pop();
		cnt++;
		for(int i = 0 ; i < V[u].size() ; ++ i){
			int j = V[u][i];
			id[j] --;
			if(id[j] == 0)q.push(j);
		}
	}
	if(cnt < n)return 1;
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(id, 0, sizeof(id));
		memset(vis, 0, sizeof(vis));
		for(int i = 1 ; i <= n ; ++ i)V[i].clear();
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			V[u].PB(v);
			id[v] ++;
		}
		printf("%d\n",topo());
	}
	return 0;
}

