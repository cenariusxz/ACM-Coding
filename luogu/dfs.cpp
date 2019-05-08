#include <bits/stdc++.h>
using namespace std;

int n;
int vis[10];

void dfs(int t){	// t 已考虑的个数，下一个从t+1开始
	if(t == n){
		for(int i = 1 ; i <= n ; ++ i){
			if(vis[i])printf("%d ",i);
		}
		printf("\n");
		return;
	}
	vis[t+1] = 1;
	dfs(t+1);
	vis[t+1] = 0;
	dfs(t+1);
}

int main(){
	n = 4;
	memset(vis,0,sizeof(vis));
	dfs(0);
	return 0;
}
