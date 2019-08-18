#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int a[15],n,k;

void dfs(int t){
	if(t == k){
		for(int i = 1 ; i <= k ; ++ i){
			printf("%d ",a[i]);	
		}
		printf("\n");
		return;
	}
	for(int i = a[t]+1 ; i <= n ; ++ i){
		a[t+1] = i;
		dfs(t+1);
	}
}

int main(){
	scanf("%d%d",&n,&k);
	dfs(0);
	return 0;
}

