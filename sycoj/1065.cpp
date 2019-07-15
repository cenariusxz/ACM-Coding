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

int a[maxn];
int n;

void dfs(int s, int t){
	if(s == 0){
		// printf("%d=",n);
		for(int i = 1 ; i <= t ; ++ i){
			printf("%d",a[i]);
			if(i == t)printf("\n");
			else printf("+");
		}
		return;
	}
	for(int i = a[t] ; i <= s ; ++ i){
		if(i == n)continue;
		a[t+1] = i;
		dfs(s-i, t+1);
	}
}

int main(){
	a[0] = 1;
	scanf("%d",&n);
	dfs(n,0);
	return 0;
}


