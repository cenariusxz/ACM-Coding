#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int fib[60], num[60];
int cnt, n;

int dfs(int t, int n){
	for(int i = t ; i <= cnt ; ++ i){
		if(n == num[i])return 1;
		if(n % num[i] == 0 && dfs(i, n / num[i]))return 1;
	}
	return 0;
}

int solve(){
	scanf("%d", &n);
	cnt = 0;
	if(n == 0 || n == 1)return 1;
	for(int i = 3 ; i <= 44 ; ++ i){
		if(n == fib[i])return 1;
		if(n % fib[i] == 0)num[++cnt] = fib[i];
	}
	if(cnt == 0)return 0;
	return dfs(1, n);
}

void init(){
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2 ; i <= 44 ; ++ i)fib[i] = fib[i-1] + fib[i-2];
}

int main(){
	init();
	int T;
	scanf("%d", &T);
	while(T--)printf(solve() ? "Yes\n" : "No\n");
	return 0;
}

