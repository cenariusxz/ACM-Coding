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

int n,m;
int a[15] = {1};
int ans = 0;

void dfs(int s, int t){
	if(s == 0){
		ans ++;
		return; 
	}
	if(t == n)return;
	for(int i = a[t] ; i <= s ; ++ i){
		a[t+1] = i;
		dfs(s-i, t+1);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ans = 0;
		scanf("%d%d",&m,&n);
		dfs(m, 0);
		printf("%d\n",ans);
	}
	return 0;
}


