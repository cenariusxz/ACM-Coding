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
ll w[maxn],sum[maxn];
int n,q;

void dfs(int s){
	sum[s] = w[s];
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		dfs(j);
		sum[s] += sum[j];
	}
}

int main(){
	scanf("%d%lld", &n, &w[1]);
	for(int i = 2 ; i <= n ; ++ i){
		int fa;
		scanf("%d%lld",&fa,&w[i]);
		V[fa].PB(i);	
	}
	scanf("%d",&q);
	dfs(1);
	while(q--){
		int id;
		scanf("%d",&id);
		printf("%lld\n",sum[id]);	
	}
	return 0;
}

