#include <bits/stdc++.h>
using namespace std;

int a[105][105];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < n ; ++ i){
		for(int j = 0 ; j < m ; ++ j){
			scanf("%d",&a[i][j]);
		}
	}
	int x,y;
	scanf("%d%d",&x,&y);
	int ans = -10000, r = 0, c = 0;
	for(int i = 0 ; i < n ; ++ i){
		if(i == x)continue;
		if(ans < a[i][y]){
			ans = a[i][y];
			r = i;
			c = y;
		}
	}
	for(int i = 0 ; i < m ; ++ i){
		if(i == y)continue;
		if(ans < a[x][i]){
			ans = a[x][i];
			r = x;
			c = i;
		}
	}
	printf("%d %d\n",r,c);
	return 0;
}
