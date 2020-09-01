#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

char s[maxn], t[maxn];
int n;

int main(){
	scanf("%d%s%s", &n, s+1, t+1);
	int ans = 0, t0 = 0, t1 = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(s[i] != t[i]){
			if(s[i] == '0')t0 ++;
			else t1 ++;
		}
	}
	ans = max(t0, t1);
	t0 = t1 = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(s[i] != t[n - i + 1]){
			if(s[i] == '0')t0 ++;
			else t1 ++;
		}
	}
	ans = min(ans, max(t0, t1) + 1);
	printf("%d\n", ans);
	return 0;
}

