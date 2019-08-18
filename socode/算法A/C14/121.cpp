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

vector<int> V[maxn];
int dep[maxn],fa[maxn];
int n,q;

void dfs(int s, int d){
	dep[s] = d;
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		dfs(j, d+1);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 2 ; i <= n ; ++ i){
		int u,v;
		scanf("%d%d",&u,&v);
		fa[v] = u;
		V[u].PB(v);
	}
	int root = 0;
	for(int i = 1 ; i <= n ; ++ i)if(fa[i] == 0)root = i;
	scanf("%d",&q);
	dfs(root,1);
	while(q--){
		int id;
		scanf("%d",&id);
		printf("%d\n",dep[id]);
	}
	return 0;
}

