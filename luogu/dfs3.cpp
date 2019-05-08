#include <bits/stdc++.h>
using namespace std;

int n;
int que[10],vis[10];
//que存放排列情况，vis存放是否访问过

void dfs(int t){	//已考虑了t个数
	if(t == n){
		for(int i = 1 ; i <= n ; ++ i){
			printf("%d ",que[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		vis[i] = 1;
		que[t+1] = i;
		dfs(t+1);
		vis[i] = 0;
	}
}

int main(){
	n = 4;
	memset(vis,0,sizeof(vis));
	dfs(0);
	return 0;
}
