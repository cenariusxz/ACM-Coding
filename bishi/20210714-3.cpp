#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e6 + 5;

int n, k, deg[maxn], vis[maxn];
vector<int> V[maxn], ans;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i < n ; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
		++ deg[a];
		++ deg[b];
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(deg[i] == 1)q.push(i), vis[i] = 1;
	}
	for(int i = 1 ; i <= k ; ++ i){
		int s = q.top(); q.pop();
		ans.PB(s);
		for(int j = 0 ; j < V[s].size() ; ++ j){
			int t = V[s][j];
			if(vis[t])continue;
			-- deg[t];
			if(deg[t] == 1)q.push(t), vis[t] = 1;
		}
	}
	sort(ans.begin(), ans.end());
	for(int i = 0 ; i < k ; ++ i){
		printf("%d", ans[i]);
		if(i == k-1)printf("\n");
		else printf(" ");
	}
	return 0;
}

