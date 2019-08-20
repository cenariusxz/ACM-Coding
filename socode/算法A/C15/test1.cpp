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

int n,m;
int vis[maxn];
vector<int> edge[maxn];

void dfs(int s){
	vis[s] = 1;
	for(int i = 0 ; i < edge[s].size(); ++ i){
		int j = edge[s][i];
		if(!vis[j])dfs(j);	
	}
}

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].PB(v);
		edge[v].PB(u);	
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(!vis[i]){
			ans++;
			dfs(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
