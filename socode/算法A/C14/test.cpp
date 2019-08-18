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

int n;
vector<int> sons[maxn];		// sons[i] -> i号节点的儿子们 
int w[maxn], f[maxn];
ll ans[maxn];

void dfs(int s){	// 求 s 为根的树的w总和 ans[s]
	ans[s] = w[s];
	// sons[s]
	for(int i = 0 ; i < sons[s].size() ; ++ i){
		int j = sons[s][i];
		dfs(j);
		ans[s] += ans[j];
	}
}

int main(){
	scanf("%d%d",&n,&w[1]);
	for(int i = 2 ; i <= n ; ++ i){
		scanf("%d%d",&f[i],&w[i]);
		sons[f[i]].PB(i);
	}
	dfs(1);
	int q;
	scanf("%d",&q);
	while(q--){
		int id;
		scanf("%d",&id);
		printf("%lld\n",ans[id]);
	}
	return 0;
}

