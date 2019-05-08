#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

char g[2010][2010];
int dis[2010][2010];
bool vis[2010];
int n;
const int INF = (1 << 29) - 1;

void Bfs(int st){
	queue<int> Q;
	Q.push(st);
	memset(vis,0,sizeof(vis));
	vis[st] = 1;
	int tdis[2010];
	for(int i = 1; i <= n; ++i) tdis[i] = n;
	tdis[st] = 0;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int i = 1; i <= n; ++i) if(g[x][i] == '1' && vis[i] == 0){
			vis[i] = 1;
			if(tdis[i] > tdis[x] + 1){
				tdis[i] = tdis[x] + 1;
				Q.push(i);
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		dis[st][i] = tdis[i];
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			dis[i][j] = INF;
		}
	}
	for(int i = 1; i <= n; ++i){
		scanf("%s",g[i] + 1);
	}
	for(int i = 1; i <= n; ++i){
		Bfs(i);
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i == j) continue;
			ans += 1ll * dis[i][j] * dis[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}
