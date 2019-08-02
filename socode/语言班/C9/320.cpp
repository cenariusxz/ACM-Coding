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
	for(int j = 0 ; j < m ; ++ j)swap(a[x][j], a[y][j]);
	for(int i = 0 ; i < n ; ++ i){
		for(int j = 0 ; j < m ; ++ j){
			printf("%d",a[i][j]);
			if(j == m-1)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
