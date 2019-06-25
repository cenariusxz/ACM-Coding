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

int n,k;
char s[10][10];
int vis[10];
int ans = 0;

void dfs(int r, int sum){	//考虑完r行，放了sum个棋子 
	if(sum == k){
		ans ++;
		return;
	}
	if(r == n)return;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i] || s[r+1][i] == '.')continue;
		vis[i] = 1;
		dfs(r+1, sum+1);
		vis[i] = 0;
	}
	dfs(r+1, sum);
}

int main(){
	while(scanf("%d%d",&n,&k)){
		if(n == -1 && k == -1)break;
		for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i] + 1);
		ans = 0;
		dfs(0,0);
		printf("%d\n",ans);	
	}
	return 0;
}


