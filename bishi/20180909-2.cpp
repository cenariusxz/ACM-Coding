#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <bitset>
using namespace std;
const int maxn = 1e3 + 5;

bitset<maxn>b[maxn];
int vis[maxn];
int n,m;

void solve(){
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		b[i].reset();
	}
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		b[u][v] = b[v][u] = 1;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		vis[i] = 1;
		for(int j = i + 1 ; j <= n ; ++ j){
			if(b[i][j])continue;
			if((b[i]|b[j]) != b[i]){
				printf("No\n");
				return;
			}
			vis[j] = 1;
		}
	}
	printf("Yes\n");
	
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
