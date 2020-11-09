#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int n, num[300];
char a[maxn], b[maxn], ans[maxn];

bool dfs(int t){	// ans == a, now ans[t]
	if(t > n)return 0;
	if(num[a[t]]){	// try ans[i] == a[i]
		ans[t] = a[t];
		num[a[t]] --;
		if(dfs(t+1))return 1;
		num[a[t]] ++;
	}
	for(int i = a[t] + 1 ; i <= '9' ; ++ i){
		if(num[i]){
			ans[t] = i;
			num[i] --;
			for(int j = t + 1 ; j <= n ; ++ j){
				for(int k = '0' ; k <= '9' ; ++ k){
					if(!num[k])continue;
					ans[j] = k;
					num[k] --;
					break;
				}
			}
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d%s%s", &n, a+1, b+1);
	for(int i = 1 ; b[i] ; ++ i)num[b[i]] ++;
	if(dfs(1))printf("%s\n", ans + 1);
	else printf("-1\n");
	return 0;
}

