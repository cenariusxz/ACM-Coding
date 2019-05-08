#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int que[15],vis[15];

void dfs(int s, int n){
	if(s == n){
		for(int i = 1 ; i <= n ; ++ i){
			printf("%5d",que[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		que[s+1] = i;
		vis[i] = 1;
		dfs(s+1,n);
		vis[i] = 0;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	dfs(0,n);
	return 0;
}

