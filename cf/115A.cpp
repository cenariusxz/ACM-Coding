#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;

int head[maxn],point[maxn],nxt[maxn],size;
int fa[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size = 0;
}

void add(int a,int b){
	point[size] = b;
	nxt[size] = head[a];
	head[a] = size++;
}

int dfs(int s){
	int ans = 1;
	for(int i = head[s] ; ~i ; i = nxt[i]){
		int j = point[i];
		ans = max(ans, dfs(j) + 1);
	}
	return ans;
}

int main(){
	init();
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d",&fa[i]);
		if(fa[i] != -1)add(fa[i],i);
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(fa[i] == -1)ans = max(ans,dfs(i));
	}
	printf("%d\n",ans);
}
