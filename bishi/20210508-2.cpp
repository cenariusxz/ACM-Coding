#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

int a[maxn], sum[maxn], res[maxn], ans, g, n = 1;
double avg = 0;
char s[maxn];

int cal(){
	double ss = 0;
	for(int i = 1 ; i <= g ; ++ i)ss += (sum[i] - avg) * (sum[i] - avg);
	return ss;
}

void dfs(int t){	//finish t items
	if(t == n){
		int tmp = cal();
		if(tmp < ans){
			ans = tmp;
			for(int i = 1 ; i <= g ; ++ i)res[i] = sum[i];
		}
		return;
	}
	for(int i = 1 ; i <= g ; ++ i){
		sum[i] += a[t+1];
		dfs(t+1);
		sum[i] -= a[t+1];
	}
}

int main(){
	scanf("%s%d", s, &g);
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == ','){
			++ n;
			continue;
		}
		a[n] = a[n] * 10 + s[i] - '0';
	}
	for(int i = 1 ; i <= n ; ++ i)avg += a[i];
	avg /= n;
	ans = INF;
	dfs(0);
	sort(res + 1, res + 1 + g);
	for(int i = 1 ; i <= g ; ++ i){
		printf("%d", res[i]);
		if(i == g)printf("\n");
		else printf(",");
	}
	return 0;
}

