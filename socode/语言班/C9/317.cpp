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
	int ans = -100000;
	for(int i = 1 ; i < n ; ++ i){
		for(int j = 1 ; j < m ; ++ j){
			int sum = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
			if(sum > ans)ans = sum;
		}
	}
	printf("%d\n",ans);
	return 0;
}
