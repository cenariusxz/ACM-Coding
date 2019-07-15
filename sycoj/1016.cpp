#include <bits/stdc++.h>
using namespace std;
int w[10005], a[105]; 

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&w[i]);
	for(int i = 1 ; i <= n ; ++ i){
		int id = 1;
		for(int j = 2 ; j <= m ; ++ j){
			if(a[id] > a[j])id = j;	
		}
		a[id] += w[i];
	}
	int ans = 0;
	for(int i = 1 ; i <= m ; ++ i)ans = max(ans, a[i]);
	printf("%d\n", ans);
	return 0;
}

