#include <bits/stdc++.h>
using namespace std;

int n,m;
int vis[10];

void dfs(int pre,int t,int m){
	//pre以考虑到哪个，t 已考虑的个数，m要选多少个
	if(t == m){
		for(int i = 1 ; i <= n ; ++ i){
			if(vis[i])printf("%d ",i);
		}
		printf("\n");
		return;
	}
	for(int i = pre + 1 ; n - i >= m - t - 1 ; ++ i){
		//这次取 i
		vis[i] = 1;
		dfs(i, t+1, m);
		vis[i] = 0;
	}
}

int main(){
	n = 5;
	memset(vis,0,sizeof(vis));
	dfs(0,0,3);
}
