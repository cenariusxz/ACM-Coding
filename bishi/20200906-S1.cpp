#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int n, a[maxn], l[maxn], r[maxn];

void solve(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i){
		l[i] = 1;
		for(int j = 1 ; j < i ; ++ j){
			if(a[j] > a[i])l[i] = max(l[i], l[j] + 1);
		}
	}
	for(int i = n ; i >= 1 ; -- i){
		r[i] = 1;
		for(int j = n ; j > i ; -- j){
			if(a[j] > a[i])r[i] = max(r[i], r[j] + 1);
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = i + 1 ; j <= n ; ++ j){
			if(a[i] == a[j])ans = max(ans, min(l[i], r[j]) * 2 );
		}
	}
	printf("%d\n", ans);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

