#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int n,a[15],vis[15];

void dfs(int t){
	if(t == n){
		for(int i = 1 ; i <= n ; ++ i){
			printf("%d",a[i]);
			if(i == n)printf("\n");
			else printf(" ");
		}
		return;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		a[t+1] = i;
		vis[i] = 1;
		dfs(t+1);
		vis[i] = 0;	
	}
}

int main(){
	scanf("%d",&n);
	dfs(0);
	return 0;
}


