#include <bits/stdc++.h>
using namespace std;

int a[15], n;
bool vis[15];

void dfs(int t){
	if(t == n){
		for(int i = 1 ; i <= n ; ++ i){
			printf("%d",a[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		a[t+1] = i;
		vis[i] = 1;
		dfs(t+1);
		a[t+1] = 0;
		vis[i] = 0;	
	}
}

int main(){
	scanf("%d",&n);
	dfs(0); 
	return 0;
}
