#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int num[20], n, m, ans = 0;
ll pow10[20];
char s[20];

void dfs(int t, ll sum){
	if(t == n){
		ans += (sum % m == 0);
		return;
	}
	int st = 0;
	if(t == 0)st = 1;	
	for(int i = st; i <= 9 ; ++ i){
		if(!num[i])continue;
		num[i] --;
		dfs(t + 1, sum + i * pow10[n - t - 1]);
		num[i] ++;
	}
}

int main(){
	pow10[0] = 1;
	for(int i = 1 ; i <= 18 ; ++ i)pow10[i] = pow10[i-1] * 10;
	scanf("%s%d", s+1, &m);
	n = strlen(s+1);
	for(int i = 1 ; s[i] ; ++ i)num[s[i] - '0'] ++;
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}

