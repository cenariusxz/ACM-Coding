#include <bits/stdc++.h>
using namespace std;

int a[105][105];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%d",&a[i][j]);
		}
	}
	int ans = -10000;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(a[i][j] > ans)ans = a[i][j];
		}
	}
	printf("%d\n",ans);
	return 0;
}
