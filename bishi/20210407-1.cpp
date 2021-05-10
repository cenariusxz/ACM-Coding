#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 2e5 + 5;

int n, cnt, vis[maxn];
char s[105], t[105];
map<string, int> M;
vector<int> V[maxn];

void dfs(int s){
	vis[s] = 1;
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int t = V[s][i];
		if(vis[t])continue;
		dfs(t);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s%s", s, t);
		string x = string(s), y = string(t);
		int idx, idy;
		if(M[x]) idx = M[x];
		else idx = M[x] = ++ cnt;
		if(M[y]) idy = M[y];
		else idy = M[y] = ++ cnt;
		V[idx].PB(idy);
		V[idy].PB(idx);
	}
	int ans = 0;
	for(int i = 1 ; i <= cnt ; ++ i){
		if(vis[i])continue;
		else{
			++ ans;
			dfs(i);
		}
	}
	printf("%d\n", ans);
	return 0;
}

